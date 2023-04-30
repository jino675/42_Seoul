/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:27:12 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/28 16:12:03 by jiryu            ###   ########.fr       */
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

void	copy_words(t_etc_2 *e, char const *s, char c);
int		malloc_guard(char **str_adr, int size);

static void	sub_cal_count(char const *s, int *i, int mode)
{
	if (mode == 1 && s[*i] == '\'')
	{
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '\'')
			*i += 1;
		if (s[*i] == '\0')
			error_exit("quote error!\n", NULL);
	}
	else if (mode == 2 && s[*i] == '{')
	{
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '}')
			*i += 1;
		if (s[*i] == '\0')
			error_exit("brace error!\n", NULL);
	}
}

static void	cal_count(t_etc_2 *e, char const *s, char c, int mode)
{
	int	i;

	e->flag = 0;
	e->count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e->flag == 1)
		{
			++e->count;
			e->flag = 0;
		}
		else if (s[i] != c)
		{
			if (e->flag == 0)
				e->flag = 1;
			sub_cal_count(s, &i, mode);
		}
	}
	if (e->flag == 1)
		++e->count;
}

static void	sub_malloc_words(t_etc_2 *e, char const *s, int *i, int mode)
{
	if (mode == 1 && s[*i] == '\'')
	{
		*i += 1;
		while (s[(*i)] != '\'')
		{
			++e->size;
			*i += 1;
		}
	}
	else if (mode == 2 && s[*i] == '{')
	{
		*i += 1;
		while (s[(*i)] != '}')
		{
			++e->size;
			*i += 1;
		}
	}
	else
		++e->size;
}

static int	malloc_words(t_etc_2 *e, char const *s, char c, int mode)
{
	int	i;

	i = -1;
	e->flag = 0;
	e->x_idx = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e->flag == 1)
		{
			e->flag = 0;
			if (malloc_guard(&e->res[++e->x_idx], e->size) == -1)
				return (-1);
		}
		else if (s[i] != c && e->flag == 0)
		{
			e->flag = 1;
			e->size = 0;
			sub_malloc_words(e, s, &i, mode);
		}
		else if (s[i] != c && e->flag == 1)
			sub_malloc_words(e, s, &i, mode);
	}
	if (e->flag == 1 && malloc_guard(&e->res[++e->x_idx], e->size) == -1)
		return (-1);
	return (0);
}

char	**split_quote_brace(char const *s, char c, int mode)
{
	int		i;
	t_etc_2	e;

	cal_count(&e, s, c, mode);
	e.res = (char **)malloc(sizeof(char *) * (e.count + 1));
	if (e.res == NULL)
		return (NULL);
	e.res[e.count] = NULL;
	if (malloc_words(&e, s, c, -1) == -1)
	{
		i = -1;
		while (++i < e.count && e.res[i] != NULL)
			free(e.res[i]);
		free(e.res);
		return (NULL);
	}
	copy_words(&e, s, c, mode);
	return (e.res);
}
