/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:40:14 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 20:40:28 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_chunk(t_chunk **chunk_addr)
{
	if ((*chunk_addr)->str != NULL)
	{
		free((*chunk_addr)->str);
		(*chunk_addr)->str = NULL;
	}
	free(*chunk_addr);
	*chunk_addr = NULL;
}

static void	sub_chunk_list_erase(t_chunk **list, int key)
{
	t_chunk	*cur_chunk;
	t_chunk	*pre_chunk;

	cur_chunk = *list;
	while (cur_chunk != NULL && cur_chunk->idx != key)
	{
		pre_chunk = cur_chunk;
		cur_chunk = cur_chunk->next;
	}
	if (cur_chunk != NULL)
		pre_chunk->next = cur_chunk->next;
	else
		pre_chunk->next = NULL;
	if (pre_chunk->next != NULL)
		pre_chunk->next->prev = pre_chunk;
	free_chunk(&cur_chunk);
}

void	chunk_list_erase(t_chunk **list, int key)
{
	t_chunk	*start;

	start = *list;
	if (start->idx == key)
	{
		*list = start->next;
		if (*list != NULL)
			(*list)->prev = NULL;
		free_chunk(&start);
		return ;
	}
	sub_chunk_list_erase(list, key);
	*list = start;
}