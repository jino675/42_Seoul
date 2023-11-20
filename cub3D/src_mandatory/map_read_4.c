/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:40:42 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 14:43:28 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_outline(t_vars *v, int i, int j)
{
	if (j + 1 == v->map_width || v->map[i][j + 1] == ' ')
		return (1);
	if (i - 1 < 0 || v->map[i - 1][j] == ' ')
		return (1);
	if (j - 1 < 0 || v->map[i][j - 1] == ' ')
		return (1);
	if (i + 1 == v->map_height || v->map[i + 1][j] == ' ')
		return (1);
	return (0);
}

static int	check_component(t_vars *v, int i, int j)
{
	int	is_p;

	is_p = 0;
	if (v->map[i][j] == 'E' || v->map[i][j] == 'S' || \
		v->map[i][j] == 'W' || v->map[i][j] == 'N')
	{
		is_p = 1;
		v->p_x = (double)j + 0.5;
		v->p_y = (double)i + 0.5;
		if (v->map[i][j] == 'E')
			v->p_d = 0;
		else if (v->map[i][j] == 'S')
			v->p_d = M_PI_2;
		else if (v->map[i][j] == 'W')
			v->p_d = M_PI;
		else if (v->map[i][j] == 'N')
			v->p_d = M_PI + M_PI_2;
		v->map[i][j] = '0';
	}
	if (v->map[i][j] != '0' && v->map[i][j] != '1' && v->map[i][j] != 'G' && \
		v->map[i][j] != 'C' && v->map[i][j] != 'O' && v->map[i][j] != ' ')
		error_exit("Error", "there's weird component!", v);
	return (is_p);
}

void	check_map(t_vars *v)
{
	int	i;
	int	j;
	int	p_cnt;
	int	g_cnt;

	p_cnt = 0;
	g_cnt = 0;
	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (++j < v->map_width)
		{
			p_cnt += check_component(v, i, j);
			if (v->map[i][j] != '1' && v->map[i][j] != ' ' && \
										is_outline(v, i, j) == 1)
				error_exit("Error", "inner components must be in!", v);
			if (v->map[i][j] == 'G')
				++g_cnt;
		}
	}
	if (p_cnt != 1)
		error_exit("Error", "player must be one!", v);
	if (g_cnt != 1)
		error_exit("Error", "goal must be one!", v);
}
