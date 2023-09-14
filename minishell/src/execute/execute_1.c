/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:07:13 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 16:07:42 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*call_expander(t_info *info, t_cmd *cmd)
{
	t_chunk	*start;

	cmd->strs = expander(info, cmd->strs);
	start = cmd->redirs;
	while (cmd->redirs)
	{
		if (cmd->redirs->token != D_IN)
			cmd->redirs->str
				= expander_str(info, cmd->redirs->str);
		cmd->redirs = cmd->redirs->next;
	}
	cmd->redirs = start;
	return (cmd);
}

void	single_cmd(t_cmd *cmd, t_info *info)
{
	int	pid;
	int	status;

	info->cmds = call_expander(info, info->cmds);
	if (cmd->builtin == my_cd || cmd->builtin == my_exit || \
		cmd->builtin == my_export || cmd->builtin == my_unset)
	{
		g_global.error_num = cmd->builtin(info, cmd);
		return ;
	}
	send_heredoc(info, cmd);
	pid = fork();
	if (pid < 0)
		print_error(5, info);
	if (pid == 0)
		handle_cmd(cmd, info);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}

int	execute(t_info *info)
{
	int		end[2];
	int		fd_in;

	fd_in = STDIN_FILENO;
	while (info->cmds)
	{
		info->cmds = call_expander(info, info->cmds);
		if (info->cmds->next)
			pipe(end);
		send_heredoc(info, info->cmds);
		ft_fork(info, end, fd_in, info->cmds);
		close(end[1]);
		if (info->cmds->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(info, end, info->cmds);
		if (info->cmds->next)
			info->cmds = info->cmds->next;
		else
			break ;
	}
	pipe_wait(info->pids, info->pipes);
	info->cmds = get_first_cmd(info->cmds);
	return (0);
}