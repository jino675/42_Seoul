/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_brace_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:35:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/30 18:42:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct s_etc_2
{
	int		x_idx;
	int		y_idx;
	int		flag;
	int		size;
	int		count;
	int		mode;
	char	**res;
}	t_etc_2;

static void	sub_copy_words(t_etc_2 *e, char const *s, char c, int *i)
{
	if (e->mode == 1 && s[*i] == '\'')
		while (s[++(*i)] != '\'')
			e->res[e->x_idx][++e->y_idx] = s[*i];
	else if (e->mode == 2 && s[*i] == '{')
	{
		if ((*i) > 0 && s[(*i) - 1] != c && s[(*i) - 1] != '}')
		{
			e->flag = 0;
			++e->x_idx;
		}
		e->res[e->x_idx][++e->y_idx] = s[*i];
		*i += 1;
		while (s[*i] != '}')
		{
			e->res[e->x_idx][++e->y_idx] = s[*i];
			*i += 1;
		}
		e->res[e->x_idx][++e->y_idx] = s[*i];
		e->flag = 0;
		++e->x_idx;
	}
	else
		e->res[e->x_idx][++e->y_idx] = s[*i];
}

void	copy_words(t_etc_2 *e, char const *s, char c)
{
	int	i;

	e->flag = 0;
	e->x_idx = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e->flag == 1)
		{
			e->flag = 0;
			++e->x_idx;
		}
		else if (s[i] != c)
		{
			if (e->flag == 0)
			{
				e->flag = 1;
				e->y_idx = -1;
			}
			sub_copy_words(e, s, c, &i);
		}
	}
}

int	malloc_guard(t_etc_2 *e, char **str_adr)
{
	e->flag = 0;
	e->size = 0;
	*str_adr = (char *)malloc(sizeof(char) * (e->size + 1));
	if (*str_adr == NULL)
		return (-1);
	(*str_adr)[e->size] = '\0';
	return (1);
}
