/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:39:59 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:37 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_wall(t_vars *v, int x, int y)
{
	if (v->map[y][x] == '1' || v->map[y][x] == 'C' || \
		v->map[y][x] == 'G')
		return (1);
	else
		return (0);
}

int	is_edge(t_vars *v, double x, double y)
{
	if (ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		is_wall(v, (int)ceil(x), (int)floor(y)) == 1)
		return (1);
	else if (floor(x) < x && x <= floor(x) + MOVING_THRES && \
		is_wall(v, (int)floor(x) - 1, (int)floor(y)) == 1)
		return (1);
	else if (ceil(y) - MOVING_THRES <= y && y < ceil(y) && \
		is_wall(v, (int)floor(x), (int)ceil(y)) == 1)
		return (1);
	else if (floor(y) < y && y <= floor(y) + MOVING_THRES && \
		is_wall(v, (int)floor(x), (int)floor(y) - 1) == 1)
		return (1);
	else
		return (0);
}

int	is_vertex(t_vars *v, double x, double y)
{
	if (ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		ceil(y) - MOVING_THRES <= y && y < ceil(y) && \
		is_wall(v, (int)ceil(x), (int)ceil(y)) == 1)
		return (1);
	else if (floor(x) < x && x <= floor(x) + MOVING_THRES && \
		ceil(y) - MOVING_THRES <= y && y < ceil(y) && \
		is_wall(v, (int)floor(x) - 1, (int)ceil(y)) == 1)
		return (1);
	else if (ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		floor(y) < y && y <= floor(y) + MOVING_THRES && \
		is_wall(v, (int)ceil(x), (int)floor(y) - 1) == 1)
		return (1);
	else if (floor(x) < x && x <= floor(x) + MOVING_THRES && \
		floor(y) < y && y <= floor(y) + MOVING_THRES && \
		is_wall(v, (int)floor(x) - 1, (int)floor(y) - 1) == 1)
		return (1);
	else
		return (0);
}
