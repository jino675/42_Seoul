/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:51:43 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 15:59:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_append_outfile(t_chunk *redirs)
{
	int	fd;

	if (redirs->token == D_OUT)
		fd = open(redirs->str,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirs->str,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

static int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: infile: No such file or directory\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

static int	handle_outfile(t_chunk *redirs)
{
	int	fd;

	fd = check_append_outfile(redirs);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	check_redirections(t_cmd *cmd)
{
	t_chunk	*start;

	start = cmd->redirs;
	while (cmd->redirs)
	{
		if (cmd->redirs->token == IN)
		{
			if (handle_infile(cmd->redirs->str))
				return (EXIT_FAILURE);
		}
		else if (cmd->redirs->token == OUT
			|| cmd->redirs->token == D_OUT)
		{
			if (handle_outfile(cmd->redirs))
				return (EXIT_FAILURE);
		}
		else if (cmd->redirs->token == D_IN)
		{
			if (handle_infile(cmd->hd_file_name))
				return (EXIT_FAILURE);
		}
		cmd->redirs = cmd->redirs->next;
	}
	cmd->redirs = start;
	return (EXIT_SUCCESS);
}