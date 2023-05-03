/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:55:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/03 21:22:04 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/pipex.h"

// static void	print_e(t_etc *e)
// {
// 	ft_printf("pids = %p\n", e->pids);
// 	for(int i = 0; e->pids != NULL && i < e->cmd_count; ++i)
// 		ft_printf("pids[%d] = %d\n", i, e->pids[i]);
// 	ft_printf("fds = %p\n", e->fds);
// 	for(int i = 0; e->fds != NULL && e->fds[i] != NULL; ++i)
// 		for(int j = 0; j < 2; ++j)
// 			ft_printf("fds[%d][%d] = %d\n", i, j, e->fds[i][j]);
// 	ft_printf("idx_pids = %d\n", e->idx_pids);
// 	ft_printf("idx_fds = %d\n", e->idx_fds);
// 	ft_printf("fd_in = %d\n", e->fd_in);
// 	ft_printf("fd_out = %d\n", e->fd_out);
// 	ft_printf("is_hd = %d\n", e->is_hd);
// 	ft_printf("idx_file = %d\n", e->idx_file);
// 	ft_printf("idx_cmd = %d\n", e->idx_cmd);
// 	ft_printf("cmd_count = %d\n", e->cmd_count);
// 	ft_printf("strs = %p\n", e->strs);
// 	for(int i = 0; e->strs != NULL && e->strs[i] != NULL; ++i)
// 		ft_printf("strs[%d] = %s\n", i, e->strs[i]);
// 	ft_printf("paths = %p\n", e->paths);
// 	for(int i = 0; e->paths != NULL && e->paths[i] != NULL; ++i)
// 		ft_printf("paths[%d] = %s\n", i, e->paths[i]);
// 	ft_printf("cmd = %p\n", e->cmd);
// 	if (e->cmd != NULL)
// 		ft_printf("cmd = %s\n", e->cmd);
// }

static void	sub_pipe_start(t_etc *e, char **argv, char **envp)
{
	e->pids[0] = fork();
	if (e->pids[0] < 0)
		error_exit(NULL, "fork error!", e);
	else if (e->pids[0] == 0)
	{
		if (e->is_hd == 1)
			e->fd_in = here_doc(e, argv[2]);
		else
		{
			e->fd_in = open(argv[1], O_RDONLY);
			if (e->fd_in == -1)
				error_exit("input", "No such file or directory", e);
		}
		pre_exec(e, argv[2 + e->is_hd], envp);
		dup2(e->fd_in, 0);
		close(e->fd_in);
		close(e->fds[0][0]);
		dup2(e->fds[0][1], 1);
		close(e->fds[0][1]);
		execve(e->cmd, e->strs, envp);
	}
	close(e->fds[0][1]);
}

static void	sub_pipe_mid(t_etc *e, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < e->cmd_count - 2)
	{
		e->idx_fds = i + 1;
		e->idx_cmd = e->is_hd + 3 + i;
		e->idx_pids = i + 1;
		e->pids[e->idx_pids] = fork();
		if (e->pids[e->idx_pids] < 0)
			error_exit(NULL, "fork error!", e);
		else if (e->pids[e->idx_pids] == 0)
		{	
			pre_exec(e, argv[e->idx_cmd], envp);
			dup2(e->fds[e->idx_fds][1], 1);
			close(e->fds[e->idx_fds][1]);
			dup2(e->fds[e->idx_fds - 1][0], 0);
			close(e->fds[e->idx_fds - 1][0]);
			execve(e->cmd, e->strs, envp);
		}
		close(e->fds[e->idx_fds - 1][0]);
		close(e->fds[e->idx_fds][1]);
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
	{	
		unlink(argv[e->idx_file]);
		e->fd_out = open(argv[e->idx_file], O_WRONLY | O_CREAT, 0644);
		if (e->fd_out == -1)
			error_exit("output", "Can't open this file", e);
		pre_exec(e, argv[e->idx_cmd], envp);
		dup2(e->fd_out, 1);
		close(e->fd_out);
		dup2(e->fds[e->idx_fds - 1][0], 0);
		close(e->fds[e->idx_fds - 1][0]);
		execve(e->cmd, e->strs, envp);
	}
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
		if (pipe(e->fds[i]) == -1)
			error_exit(NULL, "pipe error", e);
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
