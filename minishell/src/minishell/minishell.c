/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:36:41 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 15:57:01 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	chunks_clear(t_chunk **chunk_list_addr)
{
	t_chunk	*temp_chunk;

	if (*chunk_list_addr == NULL)
		return ;
	while (*chunk_list_addr != NULL)
	{
		temp_chunk = (*chunk_list_addr)->next;
		if ((*chunk_list_addr)->str != NULL)
			free((*chunk_list_addr)->str);
		free(*chunk_list_addr);
		*chunk_list_addr = temp_chunk;
	}
	*chunk_list_addr = NULL;
}

static void	cmds_clear(t_cmd **cmd_list_addr)
{
	t_cmd	*temp_cmd;
	t_chunk	*temp_redirs;

	if (*cmd_list_addr == NULL)
		return ;
	while (*cmd_list_addr != NULL)
	{
		temp_cmd = (*cmd_list_addr)->next;
		temp_redirs = (*cmd_list_addr)->redirs;
		chunks_clear(&temp_redirs);
		if ((*cmd_list_addr)->strs != NULL)
			free_strs((*cmd_list_addr)->strs);
		if ((*cmd_list_addr)->hd_file_name != NULL)
			free((*cmd_list_addr)->hd_file_name);
		free(*cmd_list_addr);
		*cmd_list_addr = temp_cmd;
	}
	*cmd_list_addr = NULL;
}

static int	prepare_executor(t_info *info)
{
	signal(SIGQUIT, sig_quit);
	g_global.in_cmd = 1;
	if (info->pipes == 0)
		single_cmd(info->cmds, info);
	else
	{
		info->pids = ft_calloc(sizeof(int), info->pipes + 2);
		if (info->pids == NULL)
			return (print_error(1, info));
		execute(info);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}

int	restart_minishell(t_info *info)
{
	cmds_clear(&info->cmds);
	free(info->line);
	if (info->pids)
		free(info->pids);
	free_strs(info->paths);
	init_info_global(info);
	info->reset = true;
	minishell(info);
	return (1);
}

int	minishell(t_info *info)
{
	char	*temp;

	info->line = readline("minishell $ ");
	temp = ft_strtrim(info->line, " ");
	if (temp == NULL)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (temp[0] == '\0')
		return (restart_minishell(info));
	add_history(info->line);
	free(info->line);
	info->line = temp;
	if (check_quotes(info->line) == 0)
		return (print_error(2, info));
	if (make_chunks(info) == 0)
		return (print_error(1, info));
	make_cmds(info);
	prepare_executor(info);
	restart_minishell(info);
	return (1);
}