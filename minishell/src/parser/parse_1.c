/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:26:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 22:36:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chunk_list_clear(t_chunk **list)
{
	t_chunk	*temp;

	if (*list == NULL)
		return ;
	while (*list != NULL)
	{
		temp = (*list)->next;
		if ((*list)->str)
			free((*list)->str);
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

int	print_token_error(t_info *info, t_chunk *chunk_list, t_token token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", \
													STDERR_FILENO);
	if (token == OUT)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == D_OUT)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == IN)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == D_IN)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	chunk_list_clear(&chunk_list);
	reset_info(info);
	return (EXIT_FAILURE);
}

static void	count_pipe(t_chunk *chunk_list, t_info *info)
{
	t_chunk	*temp;

	temp = chunk_list;
	info->pipes = 0;
	while (temp != NULL)
	{
		if (temp->token == PIPE)
			info->pipes++;
		temp = temp->next;
	}
}

static int	check_double_pipe(t_info *info, t_token token)
{
	if (token == PIPE)
	{
		print_token_error(info, info->chunk_list, info->chunk_list->token);
		return (EXIT_FAILURE);
	}
	else if (info->chunk_list != NULL)
	{
		chunk_clear_print_error(0, info, info->chunk_list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	make_cmds(t_info *info)
{
	t_cmd			*new_cmd;
	t_parse_info	parse_info;

	info->cmds = NULL;
	count_pipe(info->chunk_list, info);
	if (info->chunk_list->token == PIPE)
		return (print_token_error(info, info->chunk_list, \
								info->chunk_list->token));
	while (info->chunk_list != NULL)
	{
		if (info->chunk_list->token == PIPE)
			chunk_list_erase(&info->chunk_list, info->chunk_list->idx);
		if (check_double_pipe(info, info->chunk_list->token) != 0)
			return (EXIT_FAILURE);
		parse_info = init_parse_info(info->chunk_list, info);
		new_cmd = init_cmd(&parse_info);
		if (new_cmd == NULL)
			chunk_clear_print_error(0, info, parse_info.chunk_list);
		if (info->cmds == NULL)
			info->cmds = new_cmd;
		else
			cmd_list_push(&info->cmds, new_cmd);
		info->chunk_list = parse_info.chunk_list;
	}
	return (EXIT_SUCCESS);
}