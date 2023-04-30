/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_awk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:02:15 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/30 20:57:00 by jiryu            ###   ########.fr       */
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

static void	sub_cal_count_brace(t_etc_2 *e2, char const *s, char c, int *i)
{
	if (s[*i] == '{')
	{
		if ((*i) > 0 && s[(*i) - 1] != c && s[(*i) - 1] != '}')
			++e2->count;
		*i += 1;
		while (s[*i] != '\0' && s[*i] != '}')
		{
			printf("i = %d, %c\n", *i, s[*i]);
			*i += 1;
		}
		printf("i = %d, %c\n", *i, s[*i]);
		if (s[*i] == '\0')
			error_exit("brace error!\n", NULL);
		++e2->count;
		e2->flag = 0;
	}
}

static int	cal_count_brace(t_etc *e, t_etc_2 *e2, int idx, char c)
{
	int	i;
	int	j;

	e2->flag = 0;
	e2->count = 0;
	i = -1;
	while (e->strs[idx][++i] != '\0')
	{
		printf("i = %d, %c\n", i, e->strs[idx][i]);
		if (e->strs[idx][i] == c && e2->flag == 1)
		{
			++e2->count;
			e2->flag = 0;
		}
		else if (e->strs[idx][i] != c)
		{
			e2->flag = 1;
			sub_cal_count_brace(e2, e->strs[idx], c, &i);
		}
	}
	if (e2->flag == 1)
		++e2->count;
	j = -1;
	while (e->strs[++j] != NULL)
		printf("j = %d, %s\n", j, e->strs[j]);
	return (e2->count);
}

static void	sub_split_awk_1(t_etc *e, t_etc_2 *e2, \
								int **cur_count, int *total_count)
{
	int		i;

	i = 0;
	while (e->strs[i] != NULL)
		++i;
	*cur_count = (int *)malloc(sizeof(int) * i);
	if (*cur_count == NULL)
		error_exit("memory allocation error\n", e);
	*total_count = 0;
	i = -1;
	while (e->strs[++i] != NULL)
	{
		// ft_printf("i = %d, %s\n", i, e->strs[i]);
		// ft_printf("i + 1 = %d, %s\n", i + 1, e->strs[i + 1]);
		int j = -1;
		while (e->strs[++j] != NULL)
			printf("j = %d, %s\n", j, e->strs[j]);
		(*cur_count)[i] = cal_count_brace(e, e2, i, ' ');
		j = -1;
		while (e->strs[++j] != NULL)
			printf("j = %d, %s\n", j, e->strs[j]);
		// ft_printf("count = %d\n", (*cur_count)[i]);
		// ft_printf("i + 1 = %d, %s\n", i + 1, e->strs[i + 1]);
		*total_count += (*cur_count)[i];
	}
	e2->res = (char **)malloc(sizeof(char *) * ((*total_count) + 1));
	if (e2->res == NULL)
	{
		free(*cur_count);
		error_exit("memory allocation error\n", e);
	}
	e2->res[*total_count] = NULL;
}

static void	sub_split_awk_2(t_etc *e, t_etc_2 *e2, int *cur_count)
{
	int		i;
	int		j;
	char	**temps;

	e2->x_idx = -1;
	i = -1;
	while (e->strs[++i] != NULL)
	{
		if (cur_count[i] > 1)
		{
			temps = split_quote_brace(e->strs[i], ' ', 2);
			j = -1;
			while (++j < cur_count[i])
				e2->res[++e2->x_idx] = temps[j];
			free(temps);
			free(e->strs[i]);
		}
		else
			e2->res[++e2->x_idx] = e->strs[i];
	}
	free(e->strs);
	free(cur_count);
	e->strs = e2->res;
}

void	split_awk(t_etc *e)
{
	int		*cur_count;
	int		total_count;
	t_etc_2	e2;

	sub_split_awk_1(e, &e2, &cur_count, &total_count);
	sub_split_awk_2(e, &e2, cur_count);
}
