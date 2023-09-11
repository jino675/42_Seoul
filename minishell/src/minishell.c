/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:36:41 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 22:25:16 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	chunks_clear(t_chunk **list)
{
	t_chunk	*temp;

	if (*list == NULL)
		return ;
	while (*list != NULL)
	{
		temp = (*list)->next;
		if ((*list)->str != NULL)
			free((*list)->str);
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

static void	cmds_clear(t_cmd **list)
{
	t_cmd	*temp_cmd;
	t_chunk	*temp_redirs;

	if (*list == NULL)
		return ;
	while (*list != NULL)
	{
		temp_cmd = (*list)->next;
		temp_redirs = (*list)->redirs;
		chunks_clear(&temp_redirs);
		if ((*list)->strs != NULL)
			free_strs((*list)->strs);
		if ((*list)->hd_file_name != NULL)
			free((*list)->hd_file_name);
		free(*list);
		*list = temp_cmd;
	}
	*list = NULL;
}

int	reset_info(t_info *info)
{
	cmds_clear(&info->cmds);
	free(info->args);
	if (info->pid)
		free(info->pid);
	free_strs(info->paths);
	init_info_global(info);
	info->reset = true;
	minishell(info);
	return (1);
}

int	minishell(t_info *info)
{
	char	*temp;

	info->args = readline("minishell $ ");
	temp = ft_strtrim(info->args, " ");
	if (temp == NULL)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (temp[0] == '\0')
		return (reset_info(info));
	add_history(info->args);
	free(info->args);
	info->args = temp;
	if (check_quotes(info->args) == 0)
		return (print_error(2, info));
	if (read_token(info) == 0)
		return (print_error(1, info));
	make_cmds(info);
	// prepare_executor(info);
	reset_info(info);
	return (1);
}