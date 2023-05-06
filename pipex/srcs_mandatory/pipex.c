/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:55:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/06 22:33:05 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/pipex.h"

void	sub_pipe_start(t_etc *e, char **argv, char **envp);
void	sub_pipe_mid(t_etc *e, char **argv, char **envp);

static void	sub_sub_pipe_end(t_etc *e, char **argv, char **envp)
{
	if (access(argv[e->idx_file], F_OK) == 0 && \
			access(argv[e->idx_file], W_OK) == -1)
		error_exit(argv[e->idx_file], "Permission denied", e);
	e->fd_out = open(argv[e->idx_file], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (e->fd_out == -1)
		error_exit(argv[e->idx_file], "open error!", e);
	if (dup2(e->fds[e->idx_fds - 1][0], 0) == -1)
		error_exit(NULL, "dup2 error!", e);
	close(e->fds[e->idx_fds - 1][0]);
	if (dup2(e->fd_out, 1) == -1)
		error_exit(NULL, "dup2 error!", e);
	close(e->fd_out);
	pre_exec(e, argv[e->idx_cmd], envp);
	if (execve(e->cmd, e->strs, envp) == -1)
	{
		close(0);
		close(1);
		error_exit(NULL, "execve error!", e);
	}
}

static void	sub_pipe_end(t_etc *e, char **argv, char **envp)
{
	e->idx_fds = e->cmd_count - 1;
	e->idx_cmd = e->is_hd + 3 + e->cmd_count - 2;
	e->idx_file = e->is_hd + 3 + e->cmd_count - 1;
	e->idx_pids = e->cmd_count - 1;
	e->pids[e->idx_pids] = fork();
	if (e->pids[e->idx_pids] < 0)
		error_exit(NULL, "fork error!", e);
	else if (e->pids[e->idx_pids] == 0)
		sub_sub_pipe_end(e, argv, envp);
	close(e->fds[e->idx_fds - 1][0]);
}

static void	init_pids_fds(t_etc *e)
{
	int	i;

	e->pids = (int *)malloc(sizeof(int) * e->cmd_count);
	if (e->pids == NULL)
		error_exit(NULL, "memory allocation error", e);
	e->fds = (int **)malloc(sizeof(int *) * e->cmd_count);
	if (e->fds == NULL)
		error_exit(NULL, "memory allocation error", e);
	e->fds[e->cmd_count - 1] = NULL;
	i = -1;
	while (++i < e->cmd_count - 1)
	{
		e->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (e->fds[i] == NULL)
			error_exit(NULL, "memory allocation error", e);
	}
}

void	pipe_run(t_etc *e, int argc, char **argv, char **envp)
{
	int	i;
	int	statloc;

	if (argc >= 5 && ft_strcmp(argv[1], "here_doc") == 0)
		e->is_hd = 1;
	if (argc < 5 + e->is_hd)
		error_exit("input", "few arguments", e);
	e->cmd_count = argc - e->is_hd - 3;
	init_pids_fds(e);
	sub_pipe_start(e, argv, envp);
	sub_pipe_mid(e, argv, envp);
	sub_pipe_end(e, argv, envp);
	i = -1;
	while (++i < e->cmd_count)
		waitpid(e->pids[i], &statloc, 0);
	exit(WEXITSTATUS(statloc));
}
