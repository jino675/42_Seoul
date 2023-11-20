/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_staff_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:13:26 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/21 18:07:21 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		check_closed_vertex(t_vars *v, double x, double y);
int		check_opened_vertex(t_vars *v, double x, double y);

static void	check_goal(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		v->minimap_d == 0 && \
		(int)(v->p_d / M_PI_2) == 0 && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'G') || \
		(floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		v->minimap_d == 4 && \
		(int)(v->p_d / M_PI_2) == 2 && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'G') || \
		(ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->minimap_d == 2 && \
		(int)(v->p_d / M_PI_2) == 1 && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'G') || \
		(floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->minimap_d == 6 && \
		(int)(v->p_d / M_PI_2) == 3 && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'G'))
		v->is_end = 1;
}

static int	check_closed_edge(t_vars *v, double x, double y)
{
	if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		v->minimap_d == 0 && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'C')
		v->map[(int)floor(y)][(int)ceil(x)] = 'O';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		v->minimap_d == 4 && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'C')
		v->map[(int)floor(y)][(int)floor(x) - 1] = 'O';
	else if (ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->minimap_d == 2 && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'C')
		v->map[(int)ceil(y)][(int)floor(x)] = 'O';
	else if (floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->minimap_d == 6 && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'C')
		v->map[(int)floor(y) - 1][(int)floor(x)] = 'O';
	else
		return (0);
	return (1);
}

static int	check_opened_edge(t_vars *v, double x, double y)
{
	if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		v->minimap_d == 0 && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'O')
		v->map[(int)floor(y)][(int)ceil(x)] = 'C';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		v->minimap_d == 4 && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'O')
		v->map[(int)floor(y)][(int)floor(x) - 1] = 'C';
	else if (ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->minimap_d == 2 && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'O')
		v->map[(int)ceil(y)][(int)floor(x)] = 'C';
	else if (floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->minimap_d == 6 && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'O')
		v->map[(int)floor(y) - 1][(int)floor(x)] = 'C';
	else
		return (0);
	return (1);
}

void	use_staff(t_vars *v, int button)
{
	if (v->is_mouse_show == 0 && button == 1 && v->is_moving == 0)
	{
		if (check_closed_edge(v, v->p_x, v->p_y) == 1 || \
			check_closed_vertex(v, v->p_x, v->p_y) == 1 || \
			check_opened_edge(v, v->p_x, v->p_y) == 1 || \
			check_opened_vertex(v, v->p_x, v->p_y) == 1)
		{
			v->is_door_changed = 1;
			v->is_new_draw = 1;
		}
		check_goal(v, v->p_x, v->p_y);
		v->is_moving = 1;
	}
}
