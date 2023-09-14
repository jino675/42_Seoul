/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:59:37 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 16:08:04 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_cmd(t_cmd *cmd, t_info *info, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		print_error(4, info);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		print_error(4, info);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, info);
}

void	handle_cmd(t_cmd *cmd, t_info *info)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirs)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(info, cmd);
		exit(exit_code);
	}
	else if (cmd->strs[0][0] != '\0')
		exit_code = find_cmd(cmd, info);
	exit(exit_code);
}

int	ft_fork(t_info *info, int end[2], int fd_in, t_cmd *cmd)
{
	static int	i;

	if (info->reset == true)
	{
		i = 0;
		info->reset = false;
	}
	info->pids[i] = fork();
	if (info->pids[i] < 0)
		print_error(5, info);
	if (info->pids[i] == 0)
		dup_cmd(cmd, info, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}