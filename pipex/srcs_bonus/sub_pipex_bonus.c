/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pipex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:53:19 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/15 15:48:08 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	sub_sub_pipe_start(t_etc *e, char **av, char **envp)
{
	if (dup2(e->fd_in, 0) == -1)
		error_exit(NULL, "dup2 error!", e, 1);
	close(e->fd_in);
	close(e->fds[e->idx_fds][0]);
	if (dup2(e->fds[e->idx_fds][1], 1) == -1)
		error_exit(NULL, "dup2 error!", e, 1);
	close(e->fds[e->idx_fds][1]);
	pre_exec(e, av[e->idx_cmd], envp);
	if (execve(e->cmd, e->strs, envp) == -1)
	{
		close(0);
		close(1);
		error_exit(NULL, "execve error!", e, 1);
	}
}

void	sub_pipe_start(t_etc *e, char **av, char **envp)
{
	e->idx_fds = 0;
	e->idx_pids = 0;
	e->idx_cmd = e->is_hd + 2;
	if (pipe(e->fds[e->idx_fds]) == -1)
		error_exit(NULL, "pipe error", e, 1);
	e->pids[e->idx_pids] = fork();
	if (e->pids[e->idx_pids] < 0)
		error_exit(NULL, "fork error!", e, -1);
	else if (e->pids[e->idx_pids] == 0)
	{
		if (e->is_hd == 0)
		{
			e->fd_in = open(av[1], O_RDONLY);
			if (e->fd_in == -1)
				error_exit(av[1], "No such file or directory", e, 1);
		}
		sub_sub_pipe_start(e, av, envp);
	}
	close(e->fds[e->idx_fds][1]);
}

static void	sub_sub_pipe_mid(t_etc *e, char **av, char **envp)
{
	close(e->fds[e->idx_fds][0]);
	if (dup2(e->fds[e->idx_fds - 1][0], 0) == -1)
		error_exit(NULL, "dup2 error!", e, 1);
	close(e->fds[e->idx_fds - 1][0]);
	if (dup2(e->fds[e->idx_fds][1], 1) == -1)
		error_exit(NULL, "dup2 error!", e, 1);
	close(e->fds[e->idx_fds][1]);
	pre_exec(e, av[e->idx_cmd], envp);
	if (execve(e->cmd, e->strs, envp) == -1)
	{
		close(0);
		close(1);
		error_exit(NULL, "execve error!", e, 1);
	}
}

void	sub_pipe_mid(t_etc *e, char **av, char **envp)
{
	int	i;

	i = -1;
	while (++i < e->cmd_count - 2)
	{
		e->idx_fds = i + 1;
		e->idx_pids = i + 1;
		e->idx_cmd = e->is_hd + 3 + i;
		if (pipe(e->fds[e->idx_fds]) == -1)
			error_exit(NULL, "pipe error", e, 1);
		e->pids[e->idx_pids] = fork();
		if (e->pids[e->idx_pids] < 0)
			error_exit(NULL, "fork error!", e, -1);
		else if (e->pids[e->idx_pids] == 0)
			sub_sub_pipe_mid(e, av, envp);
		close(e->fds[e->idx_fds - 1][0]);
		close(e->fds[e->idx_fds][1]);
	}
}
