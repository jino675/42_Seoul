/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:35:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/06 18:13:48 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	sub_copy_words(t_etc_2 *e2, char const *s, int *i)
{
	if (s[*i] == '\'')
	{
		*i += 1;
		while (s[*i] != '\'')
		{
			e2->res[e2->x_idx][++e2->y_idx] = s[*i];
			*i += 1;
		}
	}
	else if (s[*i] == '\"')
	{
		*i += 1;
		while (s[*i] != '\"')
		{
			e2->res[e2->x_idx][++e2->y_idx] = s[*i];
			*i += 1;
		}
	}
	else
		e2->res[e2->x_idx][++e2->y_idx] = s[*i];
}

void	copy_words(t_etc_2 *e2, char const *s, char c)
{
	int	i;

	e2->flag = 0;
	e2->x_idx = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e2->flag == 1)
		{
			e2->flag = 0;
			++e2->x_idx;
		}
		else if (s[i] != c)
		{
			if (e2->flag == 0)
			{
				e2->flag = 1;
				e2->y_idx = -1;
			}
			sub_copy_words(e2, s, &i);
		}
	}
}

int	malloc_guard(t_etc_2 *e2, char **str_adr)
{
	int	i;

	*str_adr = (char *)malloc(sizeof(char) * (e2->each_size + 1));
	if (*str_adr == NULL)
	{
		i = -1;
		while (++i < e2->word_count && e2->res[i] != NULL)
			free(e2->res[i]);
		free(e2->res);
		return (-1);
	}
	(*str_adr)[e2->each_size] = '\0';
	return (0);
}
