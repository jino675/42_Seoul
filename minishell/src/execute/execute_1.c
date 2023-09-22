/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:07:13 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/22 17:55:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_dollar(t_info *info, t_cmd *cmd);
int		set_heredoc(t_info *info, t_cmd *cmd);
void	fork_execute(t_info *info, t_cmd *cmd, int end[2], int fd_in);
void	pipe_wait(t_info *info, int *pid, int pipe_cnt);
void	execute_cmd(t_info *info, t_cmd *cmd);
void	sig_quit(int signal);

void	execute_single(t_info *info, t_cmd *cmd)
{
	int	pid;
	int	status;

	expand_dollar(info, info->cmds);
	if (cmd->builtin == my_cd || cmd->builtin == my_exit || \
		cmd->builtin == my_export || cmd->builtin == my_unset)
	{
		info->error_num = cmd->builtin(info, cmd);
		return ;
	}
	set_heredoc(info, cmd);
	signal(SIGQUIT, sig_quit);
	pid = fork();
	if (pid < 0)
		print_error(5, info, 0);
	if (pid == 0)
		execute_cmd(info, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) != 0)
		info->error_num = WEXITSTATUS(status);
}

void	execute(t_info *info)
{
	int		end[2];
	int		fd_in;
	t_cmd	*cur_cmd;

	cur_cmd = info->cmds;
	while (cur_cmd != NULL)
	{
		expand_dollar(info, info->cmds);
		if (cur_cmd->next != NULL)
			pipe(end);
		set_heredoc(info, cur_cmd);
		signal(SIGQUIT, sig_quit);
		fork_execute(info, cur_cmd, end, fd_in);
		signal(SIGQUIT, SIG_IGN);
		close(end[1]);
		if (cur_cmd->prev)
			close(fd_in);
		if (cur_cmd->next != NULL)
			fd_in = end[0];
		cur_cmd = cur_cmd->next;
	}
	pipe_wait(info, info->pids, info->pipes);
}
