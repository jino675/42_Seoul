/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:59:37 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/22 20:26:09 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_redirections(t_cmd *cmd);

static int	run_cmd(t_cmd *cmd, t_info *info)
{
	int		i;
	char	*mycmd;

	if (access(cmd->strs[0], F_OK) == 0)
		execve(cmd->strs[0], cmd->strs, info->ev);
	i = -1;
	while (info->paths[++i] != NULL)
	{
		mycmd = ft_strjoin(info->paths[i], cmd->strs[0]);
		if (access(mycmd, F_OK) == 0)
			execve(mycmd, cmd->strs, info->ev);
		free(mycmd);
	}
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd->strs[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

void	execute_cmd(t_info *info, t_cmd *cmd)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirs != NULL)
		if (set_redirections(cmd) == EXIT_FAILURE)
			exit(1);
	if (cmd->builtin != NULL)
		exit_code = cmd->builtin(info, cmd);
	else
		exit_code = run_cmd(cmd, info);
	exit(exit_code);
}

void	fork_execute(t_info *info, t_cmd *cmd, int end[2], int fd_in)
{
	static int	i;

	if (info->reset == true)
	{
		i = 0;
		info->reset = false;
	}
	info->pids[i] = fork();
	if (info->pids[i] < 0)
		print_error(5, info, 0);
	if (info->pids[i] == 0)
	{
		if (cmd->prev != NULL && dup2(fd_in, STDIN_FILENO) < 0)
			print_error(4, info, 1);
		close(end[0]);
		if (cmd->next != NULL && dup2(end[1], STDOUT_FILENO) < 0)
			print_error(4, info, 1);
		close(end[1]);
		if (cmd->prev != NULL)
			close(fd_in);
		execute_cmd(info, cmd);
	}
	++i;
}

void	pipe_wait(t_info *info, int *pid, int pipe_cnt)
{
	int	i;
	int	status;

	i = -1;
	while (++i < pipe_cnt + 1)
		waitpid(pid[i], &status, 0);
	if (WIFEXITED(status) != 0)
		info->error_num = WEXITSTATUS(status);
}
