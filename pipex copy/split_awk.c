/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_awk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:02:15 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/28 16:03:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sub_split_awk(t_etc *e, int *cur_count, char **res)
{
	int		i;
	int		j;
	int		res_idx;
	char	**temps;

	res_idx = -1;
	i = -1;
	while (e->strs[++i] != NULL)
	{
		if (cur_count[i] > 1)
		{
			temps = ft_split(e->strs[i], ' ');
			j = -1;
			while (++j < cur_count[i])
				res[++res_idx] = temps[j];
			free(temps);
			free(e->strs[i]);
		}
		else
			res[++res_idx] = e->strs[i];
	}
	free(e->strs);
	free(cur_count);
}

void	split_awk(t_etc *e)
{
	int		i;
	int		*cur_count;
	int		total_count;
	char	**res;

	total_count = 0;
	i = 0;
	while (e->strs[i] != NULL)
		++i;
	cur_count = (int *)malloc(sizeof(int) * i);
	if (cur_count == NULL)
		error_exit("memory allocation error\n", e);		
	i = -1;
	while (e->strs[++i] != NULL)
	{
		cur_count[i] = cal_count(e->strs[i], ' ');
		total_count += cur_count[i];
	}
	res = (char **)malloc(sizeof(char *) * (total_count + 1));
	if (res == NULL)
	{
		free(cur_count);
		error_exit("memory allocation error\n", e);
	}
	res[total_count] = NULL;
	sub_split_awk(e, cur_count, res);
	e->strs = res;
}
