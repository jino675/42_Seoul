/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:35:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/28 16:12:43 by jiryu            ###   ########.fr       */
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
	char	**res;
}	t_etc_2;

static void	sub_copy_words(t_etc_2 *e, char const *s, int *i)
{
	if (mode == 1 && s[*i] == '\'')
	{
		*i += 1;
		while (s[*i] != '\'')
		{
			e->res[e->x_idx][++e->y_idx] = s[*i];
			*i += 1;
		}
	}
	else if (mode == 2 && s[*i] == '{')
	{
		*i += 1;
		while (s[*i] != '}')
		{
			e->res[e->x_idx][++e->y_idx] = s[*i];
			*i += 1;
		}
	}
	else
		e->res[e->x_idx][++e->y_idx] = s[*i];
}

void	copy_words(t_etc_2 *e, char const *s, char c, int mode)
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
			sub_copy_words(e, s, &i, mode);
		}
	}
}

int	malloc_guard(char **str_adr, int size)
{
	*str_adr = (char *)malloc(sizeof(char) * (size + 1));
	if (*str_adr == NULL)
		return (-1);
	(*str_adr)[size] = '\0';
	return (1);
}
