/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_staff_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:38:55 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/21 18:07:02 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	sub_check_closed_vertex(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) && \
		floor(y) < y && y <= floor(y) + STAFF_THRES) && \
		!(ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		floor(y) < y && y <= floor(y) + MOVING_THRES) && \
		v->minimap_d == 7 && \
		v->map[(int)floor(y) - 1][(int)ceil(x)] == 'C')
		v->map[(int)floor(y) - 1][(int)ceil(x)] = 'O';
	else if ((floor(x) < x && x <= floor(x) + STAFF_THRES && \
		floor(y) < y && y <= floor(y) + STAFF_THRES) && \
		!(floor(x) < x && x <= floor(x) + MOVING_THRES && \
		floor(y) < y && y <= floor(y) + MOVING_THRES) && \
		v->minimap_d == 5 && \
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] == 'C')
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] = 'O';
	else
		return (0);
	return (1);
}

int	check_closed_vertex(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y)) && \
		!(ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		ceil(y) - MOVING_THRES <= y && y < ceil(y)) && \
		v->minimap_d == 1 && \
		v->map[(int)ceil(y)][(int)ceil(x)] == 'C')
		v->map[(int)ceil(y)][(int)ceil(x)] = 'O';
	else if ((floor(x) < x && x <= floor(x) + STAFF_THRES && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y)) && \
		!(floor(x) < x && x <= floor(x) + MOVING_THRES && \
		ceil(y) - MOVING_THRES <= y && y < ceil(y)) && \
		v->minimap_d == 3 && \
		v->map[(int)ceil(y)][(int)floor(x) - 1] == 'C')
		v->map[(int)ceil(y)][(int)floor(x) - 1] = 'O';
	else if (sub_check_closed_vertex(v, x, y) == 0)
		return (0);
	return (1);
}

static int	sub_check_opened_vertex(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) && \
		floor(y) < y && y <= floor(y) + STAFF_THRES) && \
		!(ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		floor(y) < y && y <= floor(y) + MOVING_THRES) && \
		v->minimap_d == 7 && \
		v->map[(int)floor(y) - 1][(int)ceil(x)] == 'O')
		v->map[(int)floor(y) - 1][(int)ceil(x)] = 'C';
	else if ((floor(x) < x && x <= floor(x) + STAFF_THRES && \
		floor(y) < y && y <= floor(y) + STAFF_THRES) && \
		!(floor(x) < x && x <= floor(x) + MOVING_THRES && \
		floor(y) < y && y <= floor(y) + MOVING_THRES) && \
		v->minimap_d == 5 && \
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] == 'O')
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] = 'C';
	else
		return (0);
	return (1);
}

int	check_opened_vertex(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y)) && \
		!(ceil(x) - MOVING_THRES <= x && x < ceil(x) && \
		ceil(y) - MOVING_THRES <= y && y < ceil(y)) && \
		v->minimap_d == 1 && \
		v->map[(int)ceil(y)][(int)ceil(x)] == 'O')
		v->map[(int)ceil(y)][(int)ceil(x)] = 'C';
	else if ((floor(x) < x && x <= floor(x) + STAFF_THRES && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y)) && \
		!(floor(x) < x && x <= floor(x) + MOVING_THRES && \
		ceil(y) - MOVING_THRES <= y && y < ceil(y)) && \
		v->minimap_d == 3 && \
		v->map[(int)ceil(y)][(int)floor(x) - 1] == 'O')
		v->map[(int)ceil(y)][(int)floor(x) - 1] = 'C';
	else if (sub_check_opened_vertex(v, x, y) == 0)
		return (0);
	return (1);
}
