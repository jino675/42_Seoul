/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:07:13 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/28 19:49:02 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_quit_no_msg(int signal);
void	sig_quit_with_msg(int signal);
void	expand_dollar(t_info *info, t_cmd *cmd);
int		set_heredoc(t_info *info, t_cmd *cmd);
void	fork_execute(t_info *info, t_cmd *cmd, int end[2], int fd_in);
void	pipe_wait(t_info *info, int *pid, int pipe_cnt);
void	execute_cmd(t_info *info, t_cmd *cmd);

void	execute_single(t_info *info, t_cmd *cmd)
{
	int	pid;
	int	status;

	expand_dollar(info, info->cmds);
	set_heredoc(info, cmd);
	signal(SIGQUIT, sig_quit_with_msg);
	pid = fork();
	if (pid < 0)
		print_error(5, info, 0);
	if (pid == 0)
		execute_cmd(info, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) != 0)
		info->error_num = WEXITSTATUS(status);
	if (cmd->is_outfile == false && cmd->builtin != NULL)
		cmd->builtin(info, cmd);
}

void	execute(t_info *info)
{
	int		end[2];
	int		fd_in;
	t_cmd	*cur_cmd;

	cur_cmd = info->cmds;
	while (cur_cmd != NULL)
	{
		expand_dollar(info, cur_cmd);
		if (cur_cmd->next != NULL)
			pipe(end);
		set_heredoc(info, cur_cmd);
		signal(SIGQUIT, sig_quit_no_msg);
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
