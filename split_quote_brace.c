/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_brace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:27:12 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/01 15:29:06 by jiryu            ###   ########.fr       */
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

void	copy_words(t_etc_2 *e, char const *s, char c);
int		malloc_guard(t_etc_2 *e, char **str_adr);

static void	sub_cal_count(t_etc_2 *e, char const *s, char c, int *i)
{
	if (e->mode == 1 && s[*i] == '\'')
	{
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '\'')
			*i += 1;
		if (s[*i] == '\0')
			error_exit("quote error!\n", NULL);
	}
	else if (e->mode == 2 && s[*i] == '{')
	{
		if ((*i) > 0 && s[(*i) - 1] != c && s[(*i) - 1] != '}')
			++e->count;
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '}')
			*i += 1;
		if (s[*i] == '\0')
			error_exit("brace error!\n", NULL);
		++e->count;
		e->flag = 0;
	}
}

static void	cal_count(t_etc_2 *e, char const *s, char c)
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
			e->flag = 1;
			sub_cal_count(e, s, c, &i);
		}
	}
	if (e->flag == 1)
		++e->count;
}

static int	sub_malloc_words(t_etc_2 *e, char const *s, char c, int *i)
{
	if (e->mode == 1 && s[*i] == '\'')
		while (s[++(*i)] != '\'')
			++e->size;
	else if (e->mode == 2 && s[*i] == '{')
	{
		if (*i > 0 && s[(*i) - 1] != c && s[(*i) - 1] != '}')
			if (malloc_guard(e, &e->res[++e->x_idx]) == -1)
				return (-1);
		e->size += 1;
		*i += 1;
		while (s[(*i)] != '}')
		{
			++e->size;
			*i += 1;
		}
		e->size += 1;
		if (malloc_guard(e, &e->res[++e->x_idx]) == -1)
			return (-1);
	}
	else
		++e->size;
	return (0);
}

static int	malloc_words(t_etc_2 *e, char const *s, char c)
{
	int	i;

	i = -1;
	e->size = 0;
	e->flag = 0;
	e->x_idx = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e->flag == 1)
		{
			if (malloc_guard(e, &e->res[++e->x_idx]) == -1)
				return (-1);
		}
		else if (s[i] != c)
		{
			e->flag = 1;
			sub_malloc_words(e, s, c, &i);
		}
	}
	if (e->flag == 1)
		if (malloc_guard(e, &e->res[++e->x_idx]) == -1)
			return (-1);
	return (0);
}

char	**split_quote_brace(char const *s, char c, int mode)
{
	int		i;
	t_etc_2	e;

	e.mode = mode;
	cal_count(&e, s, c);
	e.res = (char **)malloc(sizeof(char *) * (e.count + 1));
	if (e.res == NULL)
		return (NULL);
	ft_printf("e.count : %d\n", e.count);
	e.res[e.count] = NULL;
	if (malloc_words(&e, s, c) == -1)
	{
		i = -1;
		while (++i < e.count && e.res[i] != NULL)
			free(e.res[i]);
		free(e.res);
		return (NULL);
	}
	copy_words(&e, s, c);
	return (e.res);
}
