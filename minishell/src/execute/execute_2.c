/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:08:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 16:05:04 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_heredoc(t_chunk *heredoc, bool quotes, t_info *info, \
															char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline("> ");
	while (line && ft_strncmp(heredoc->str, line, ft_strlen(heredoc->str))
		&& !g_global.stop_heredoc)
	{
		if (quotes == false)
			line = expander_str(info, line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	if (g_global.stop_heredoc || !line)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

static int	ft_heredoc(t_info *info, t_chunk *heredoc, char *file_name)
{
	bool	quotes;
	int		sl;

	sl = EXIT_SUCCESS;
	if ((heredoc->str[0] == '\"'
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
		|| (heredoc->str[0] == '\''
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
		quotes = true;
	else
		quotes = false;
	delete_quotes(heredoc->str, '\"');
	delete_quotes(heredoc->str, '\'');
	g_global.stop_heredoc = 0;
	g_global.in_heredoc = 1;
	sl = create_heredoc(heredoc, quotes, info, file_name);
	g_global.in_heredoc = 0;
	info->heredoc = true;
	return (sl);
}

static char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	check_fd_heredoc(t_info *info, int end[2], t_cmd *cmd)
{
	int	fd_in;

	if (info->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}

int	send_heredoc(t_info *info, t_cmd *cmd)
{
	int		sl;
	t_chunk	*start;

	start = cmd->redirs;
	sl = EXIT_SUCCESS;
	while (cmd->redirs)
	{
		if (cmd->redirs->token == D_IN)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = generate_heredoc_filename();
			sl = ft_heredoc(info, cmd->redirs, cmd->hd_file_name);
			if (sl)
			{
				g_global.error_num = 1;
				return (restart_minishell(info));
			}
		}
		cmd->redirs = cmd->redirs->next;
	}
	cmd->redirs = start;
	return (EXIT_SUCCESS);
}