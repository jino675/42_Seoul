/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:56:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/20 18:51:38 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		is_edge(t_vars *v, double x, double y);
int		is_vertex(t_vars *v, double x, double y);

static void	update_loc(t_vars *v, double x, double y)
{
	v->p_x = x;
	v->p_y = y;
}

static void	meet_wall(t_vars *v, double x, double y)
{
	if (((ceil(y) - MOVING_THRES <= y && y < ceil(y)) || \
		(floor(y) < y && y <= floor(y) + MOVING_THRES)) && \
		((ceil(x) - MOVING_THRES <= x && x < ceil(x)) || \
		(floor(x) < x && x <= floor(x) + MOVING_THRES)))
	{
		if (is_edge(v, v->p_x, y) == 0 && is_vertex(v, v->p_x, y) == 0)
			v->p_y = y;
		else if (is_edge(v, x, v->p_y) == 0 && is_vertex(v, x, v->p_y) == 0)
			v->p_x = x;
	}
	else if ((ceil(y) - MOVING_THRES <= y && y < ceil(y)) || \
		(floor(y) < y && y <= floor(y) + MOVING_THRES))
	{
		if (is_edge(v, x, v->p_y) == 0 && is_vertex(v, x, v->p_y) == 0)
			v->p_x = x;
	}
	else if ((ceil(x) - MOVING_THRES <= x && x < ceil(x)) || \
		(floor(x) < x && x <= floor(x) + MOVING_THRES))
	{
		if (is_edge(v, v->p_x, y) == 0 && is_vertex(v, v->p_x, y) == 0)
			v->p_y = y;
	}
}

static void	sub_move_player_1(t_vars *v, int key)
{
	double	new_x;
	double	new_y;

	if (key == W)
	{
		new_x = v->p_x + MOVING_UNIT * cos(v->p_d);
		new_y = v->p_y + MOVING_UNIT * sin(v->p_d);
		if (is_edge(v, new_x, new_y) == 0 && is_vertex(v, new_x, new_y) == 0)
			update_loc(v, new_x, new_y);
		else
			meet_wall(v, new_x, new_y);
	}
	else if (key == A)
	{
		new_x = v->p_x + MOVING_UNIT * cos(v->p_d + M_PI + M_PI_2);
		new_y = v->p_y + MOVING_UNIT * sin(v->p_d + M_PI + M_PI_2);
		if (is_edge(v, new_x, new_y) == 0 && is_vertex(v, new_x, new_y) == 0)
			update_loc(v, new_x, new_y);
		else
			meet_wall(v, new_x, new_y);
	}
}

static void	sub_move_player_2(t_vars *v, int key)
{
	double	new_x;
	double	new_y;

	if (key == S)
	{
		new_x = v->p_x + MOVING_UNIT * cos(v->p_d + M_PI);
		new_y = v->p_y + MOVING_UNIT * sin(v->p_d + M_PI);
		if (is_edge(v, new_x, new_y) == 0 && is_vertex(v, new_x, new_y) == 0)
			update_loc(v, new_x, new_y);
		else
			meet_wall(v, new_x, new_y);
	}
	else if (key == D)
	{
		new_x = v->p_x + MOVING_UNIT * cos(v->p_d + M_PI_2);
		new_y = v->p_y + MOVING_UNIT * sin(v->p_d + M_PI_2);
		if (is_edge(v, new_x, new_y) == 0 && is_vertex(v, new_x, new_y) == 0)
			update_loc(v, new_x, new_y);
		else
			meet_wall(v, new_x, new_y);
	}
}

void	move_player(t_vars *v, int key)
{
	const double	pre_x = v->p_x;
	const double	pre_y = v->p_y;

	sub_move_player_1(v, key);
	sub_move_player_2(v, key);
	if (v->p_x != pre_x || v->p_y != pre_y)
		v->is_new_draw = 1;
	else
		return ;
}
