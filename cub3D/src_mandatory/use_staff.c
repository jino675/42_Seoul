/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_staff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:13:26 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/18 01:25:14 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_closed(t_vars *v, double x, double y)
{
	if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'C')
		v->map[(int)floor(y)][(int)ceil(x)] = 'O';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'C')
		v->map[(int)floor(y)][(int)floor(x) - 1] = 'O';
	else if (ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'C')
		v->map[(int)ceil(y)][(int)floor(x)] = 'O';
	else if (floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'C')
		v->map[(int)floor(y) - 1][(int)floor(x)] = 'O';
	else if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)ceil(x)] == 'C')
		v->map[(int)ceil(y)][(int)ceil(x)] = 'O';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)floor(x) - 1] == 'C')
		v->map[(int)ceil(y)][(int)floor(x) - 1] = 'O';
	else if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)ceil(x)] == 'C')
		v->map[(int)floor(y) - 1][(int)ceil(x)] = 'O';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] == 'C')
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] = 'O';
	else
		return (0);
	return (1);
}

static int	check_opened(t_vars *v, double x, double y)
{
	if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'O')
		v->map[(int)floor(y)][(int)ceil(x)] = 'C';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'O')
		v->map[(int)floor(y)][(int)floor(x) - 1] = 'C';
	else if (ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'O')
		v->map[(int)ceil(y)][(int)floor(x)] = 'C';
	else if (floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'O')
		v->map[(int)floor(y) - 1][(int)floor(x)] = 'C';
	else if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)ceil(x)] == 'O')
		v->map[(int)ceil(y)][(int)ceil(x)] = 'C';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)floor(x) - 1] == 'O')
		v->map[(int)ceil(y)][(int)floor(x) - 1] = 'C';
	else if (ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)ceil(x)] == 'O')
		v->map[(int)floor(y) - 1][(int)ceil(x)] = 'C';
	else if (floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] == 'O')
		v->map[(int)floor(y) - 1][(int)floor(x) - 1] = 'C';
	else
		return (0);
	return (1);
}

static void	check_goal(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'G') || \
		(floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'G') || \
		(ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'G') || \
		(floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'G'))
		v->is_end = 1;
}

void	use_staff(t_vars *v, int button)
{
	if (button == 1 && v->is_moving == 0)
	{
		printf("%lf %lf %lf %lf %c\n", v->p_x, v->p_y, floor(v->p_x), floor(v->p_y), v->map[(int)floor(v->p_y) - 1][(int)floor(v->p_x) - 1]);
		if (check_closed(v, v->p_x, v->p_y) == 1 || \
			check_opened(v, v->p_x, v->p_y) == 1)
			v->new_draw = 1;
		check_goal(v, v->p_x, v->p_y);
		v->is_moving = 1;
	}
}
