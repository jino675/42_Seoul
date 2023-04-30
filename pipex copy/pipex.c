/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:55:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/27 21:38:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	take_input(int argc, char **argv, char **envp)
// {
// 	int fd
// }


// 	int		pid_1;
// 	int		pid_2;
// 	int		fd_pipe[2];
// 	int		fd_in;
// 	int		fd_out;
// 	char	**cmd_1;
// 	char	**cmd_2;
// void	init_etc(t_etc *e)
// {
// 	pipe(e->fd_pipe);
// }

// static void	sub_free(char **strs)
// {
// 	int	i;

// 	i = -1;
// 	while (strs[++i] != NULL)
// 		free(strs[i]);
// 	free(strs);
// }

static void	sub_pipe_start(t_etc *e, char **argv, char **envp)
{
	e->pids[0] = fork();
	if (e->pids[0] < 0)
	{
		error_exit("fork error!\n", e);
	}
	else if (e->pids[0] == 0)
	{
		pre_exec(e, argv[2], envp);

		e->fd_in = open(argv[1], O_RDONLY);
		dup2(e->fd_in, 0);
		close(e->fd_in);
		
		close(e->fds[0][0]);
		dup2(e->fds[0][1], 1);
		close(e->fds[0][1]);
		execve(e->cmd, e->strs, envp);
	}
	close(e->fds[0][1]);
}

static void	sub_pipe_mid(t_etc *e, int argc, char **argv, char **envp)
{
	int	i;
	int	idx_fds;
	int	idx_cmd;

	i = -1;
	while (++i < argc - 5)
	{
		idx_fds = i;
		idx_cmd = i + 3;

		e->pids[i + 1] = fork();
		if (e->pids[i + 1] < 0)
		{
			error_exit("fork error!\n", e);
		}
		else if (e->pids[i + 1] == 0)
		{	
			pre_exec(e, argv[idx_cmd], envp);
			
			dup2(e->fds[idx_fds + 1][1], 1);
			close(e->fds[idx_fds + 1][1]);
			dup2(e->fds[idx_fds][0], 0);
			close(e->fds[idx_fds][0]);
			execve(e->cmd, e->strs, envp);
		}
		close(e->fds[idx_fds][0]);
		close(e->fds[idx_fds + 1][1]);
	}
}

static void	sub_pipe_end(t_etc *e, int argc, char **argv, char **envp)
{
	int	idx_fds;
	int	idx_cmd;
	int	idx_file;

	idx_fds = argc - 5;
	idx_cmd = argc - 2;
	idx_file = argc - 1;
	e->pids[argc - 4] = fork();
	if (e->pids[argc - 4] < 0)
	{
		error_exit("fork error!\n", e);
	}
	else if (e->pids[argc - 4] == 0)
	{	
		pre_exec(e, argv[idx_cmd], envp);
		unlink(argv[idx_file]);
		e->fd_out = open(argv[idx_file], O_WRONLY | O_CREAT, 0644 | O_TRUNC);
		dup2(e->fd_out, 1);
		close(e->fd_out);
		
		close(e->fds[idx_fds][1]);
		dup2(e->fds[idx_fds][0], 0);
		close(e->fds[idx_fds][0]);
		execve(e->cmd, e->strs, envp);
	}
	close(e->fds[idx_fds][0]);
}

static void	init_pids_fds(t_etc *e, int argc)
{
	int	i;

	e->pids = (int *)malloc(sizeof(int) * (argc - 3));
	if (e->pids == NULL)
		error_exit("memory allocation error\n", e);
	e->fds = (int **)malloc(sizeof(int *) * (argc - 4 + 1));
	if (e->fds == NULL)
		error_exit("memory allocation error\n", e);
	e->fds[argc - 4] = NULL;
	i = -1;
	while (++i < argc - 4)
	{
		e->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (e->fds[i] == NULL)
			error_exit("memory allocation error\n", e);
		pipe(e->fds[i]);
	}
}

void	pipe_run(t_etc *e, int argc, char **argv, char **envp)
{
	int	i;

	if (argc < 5)
		error_exit("wrong input!\n", e);
	init_pids_fds(e, argc);
	sub_pipe_start(e, argv, envp);
	sub_pipe_mid(e, argc, argv, envp);
	sub_pipe_end(e, argc, argv, envp);
	i = -1;
	while (++i < argc - 3)
		waitpid(e->pids[i], NULL, 0);
}
