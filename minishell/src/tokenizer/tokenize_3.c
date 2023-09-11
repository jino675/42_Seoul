/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:33:28 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 21:40:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_chunk	*chunk_new(char *str, int token)
{
	static int	i;
	t_chunk		*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (new_chunk == NULL)
		return (0);
	new_chunk->str = str;
	new_chunk->token = token;
	new_chunk->idx = i++;
	if (i < 0)
		i = 0;
	new_chunk->next = NULL;
	new_chunk->prev = NULL;
	return (new_chunk);
}

void	chunk_list_push(t_chunk **list, t_chunk *new_chunk)
{
	t_chunk	*temp;

	temp = *list;
	if (*list == NULL)
	{
		*list = new_chunk;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_chunk;
	new_chunk->prev = temp;
}

t_token	check_token(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (OUT);
	else if (c == '<')
		return (IN);
	return (0);
}

int	make_new_chunk(char *str, t_token token, t_chunk **chunk_list)
{
	t_chunk	*new_chunk;

	new_chunk = chunk_new(str, token);
	if (new_chunk == NULL)
		return (0);
	chunk_list_push(chunk_list, new_chunk);
	return (1);
}

int	add_token(char *str, t_chunk **chunk_list)
{
	t_token	token;

	token = check_token(str[0]);
	if (token == OUT && check_token(str[1]) == OUT)
	{
		if (make_new_chunk(NULL, D_OUT, chunk_list) == 0)
			return (-1);
		return (2);
	}
	else if (token == IN && check_token(str[1]) == IN)
	{
		if (make_new_chunk(NULL, D_IN, chunk_list) == 0)
			return (-1);
		return (2);
	}
	else if (token != 0)
	{
		if (make_new_chunk(NULL, token, chunk_list) == 0)
			return (-1);
		return (1);
	}	
	return (0);
}