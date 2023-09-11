/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:53:07 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 22:19:10 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse_info	init_parse_info(t_chunk *chunk_list, t_info *info)
{
	t_parse_info	temp;

	temp.chunk_list = chunk_list;
	temp.redirs = NULL;
	temp.num_redirs = 0;
	temp.info = info;
	return (temp);
}

static int	add_redirection(t_chunk *cur_chunk, t_parse_info *parse_info)
{
	t_chunk	*new_chunk;

	new_chunk = chunk_new(ft_strdup(cur_chunk->next->str), cur_chunk->token);
	if (new_chunk == NULL)
		chunk_clear_print_error(1, parse_info->info, parse_info->chunk_list);
	chunk_list_push(&parse_info->redirs, new_chunk);
	chunk_list_erase(&parse_info->chunk_list, cur_chunk->idx);
	chunk_list_erase(&parse_info->chunk_list, cur_chunk->next->idx);
	++parse_info->num_redirs;
	return (0);
}

static void	collect_redirection(t_parse_info *parse_info)
{
	t_chunk	*cur_chunk;

	cur_chunk = parse_info->chunk_list;
	while (cur_chunk != NULL && cur_chunk->token == 0)
		cur_chunk = cur_chunk->next;
	if (cur_chunk == NULL || cur_chunk->token == PIPE)
		return ;
	if (cur_chunk->next == NULL)
		chunk_clear_print_error(0, parse_info->info, parse_info->chunk_list);
	if (cur_chunk->next->token != 0)
		print_token_error(parse_info->info,
			parse_info->chunk_list, cur_chunk->next->token);
	if ((cur_chunk->token >= OUT && cur_chunk->token <= D_IN))
		add_redirection(cur_chunk, parse_info);
	collect_redirection(parse_info);
}

static int	count_cur_args(t_chunk *chunk_list)
{
	int		i;
	t_chunk	*cur_chunk;

	i = 0;
	cur_chunk = chunk_list;
	while (cur_chunk != NULL && cur_chunk->token != PIPE)
	{
		if (cur_chunk->idx >= 0)
			++i;
		cur_chunk = cur_chunk->next;
	}
	return (i);
}

t_cmd	*init_cmd(t_parse_info *parse_info)
{
	int		i;
	int		cnt_cur_arg;
	char	**str;
	t_chunk	*cur_chunk;

	collect_redirection(parse_info);
	cnt_cur_arg = count_cur_args(parse_info->chunk_list);
	str = ft_calloc(cnt_cur_arg + 1, sizeof(char *));
	if (str == NULL)
		chunk_clear_print_error(1, parse_info->info, parse_info->chunk_list);
	i = -1;
	cur_chunk = parse_info->chunk_list;
	while (--cnt_cur_arg >= 0)
	{
		if (cur_chunk->str != NULL)
		{
			str[++i] = ft_strdup(cur_chunk->str);
			chunk_list_erase(&parse_info->chunk_list, cur_chunk->idx);
			cur_chunk = parse_info->chunk_list;
		}
	}
	return (cmd_new(str, parse_info->num_redirs, parse_info->redirs));
}