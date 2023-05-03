/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:27:12 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/03 18:19:23 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr_bonus/pipex_bonus.h"

typedef struct s_etc_2
{
	int		x_idx;
	int		y_idx;
	int		flag;
	int		each_size;
	int		word_count;
	char	**res;
}	t_etc_2;

void	copy_words(t_etc_2 *e2, char const *s, char c);
int		malloc_guard(t_etc_2 *e2, char **str_adr);

static int	sub_cal_count(char const *s, int *i)
{
	if (s[*i] == '\'')
	{
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '\'')
			*i += 1;
		if (s[*i] == '\0')
			return (-1);
	}
	else if (s[*i] == '\"')
	{
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '\"')
			*i += 1;
		if (s[*i] == '\0')
			return (-1);
	}
	return (0);
}

static int	cal_count(t_etc_2 *e2, char const *s, char c)
{
	int	i;

	e2->flag = 0;
	e2->word_count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e2->flag == 1)
		{
			++e2->word_count;
			e2->flag = 0;
		}
		else if (s[i] != c)
		{
			e2->flag = 1;
			if (sub_cal_count(s, &i) == -1)
				return (-1);
		}
	}
	if (e2->flag == 1)
		++e2->word_count;
	return (0);
}

static void	sub_malloc_words(t_etc_2 *e2, char const *s, int *i)
{
	if (s[*i] == '\'')
	{
		*i += 1;
		while (s[*i] != '\'')
		{
			++e2->each_size;
			*i += 1;
		}
	}
	else if (s[*i] == '\"')
	{
		*i += 1;
		while (s[*i] != '\"')
		{
			++e2->each_size;
			*i += 1;
		}
	}
	else
		++e2->each_size;
}

static int	malloc_words(t_etc_2 *e2, char const *s, char c)
{
	int	i;

	i = -1;
	e2->each_size = 0;
	e2->flag = 0;
	e2->x_idx = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && e2->flag == 1)
		{
			if (malloc_guard(e2, &e2->res[++e2->x_idx]) == -1)
				return (-1);
			e2->flag = 0;
			e2->each_size = 0;
		}
		else if (s[i] != c)
		{
			e2->flag = 1;
			sub_malloc_words(e2, s, &i);
		}
	}
	if (e2->flag == 1)
		if (malloc_guard(e2, &e2->res[++e2->x_idx]) == -1)
			return (-1);
	return (0);
}

char	**split_quote(char const *s, char c)
{
	t_etc_2	e2;

	if (cal_count(&e2, s, c) == -1)
		return (NULL);
	e2.res = (char **)malloc(sizeof(char *) * (e2.word_count + 1));
	if (e2.res == NULL)
		return (NULL);
	e2.res[e2.word_count] = NULL;
	if (malloc_words(&e2, s, c) == -1)
		return (NULL);
	copy_words(&e2, s, c);
	return (e2.res);
}
