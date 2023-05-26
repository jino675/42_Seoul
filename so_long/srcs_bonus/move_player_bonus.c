/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:56:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:08:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/so_long_bonus.h"

static void	pre_move_player(t_vars *v)
{
	v->p_s = 0;
	v->is_moving_p = 1;
	++v->move_count;
	if (v->map[v->p_y][v->p_x] == 'E' && v->c_count == 0)
		normal_exit(v);
	if (v->map[v->p_y][v->p_x] == 'C')
	{
		--v->c_count;
		v->map[v->p_y][v->p_x] = '0';
	}
}

static void	sub_move_player_1(t_vars *v, int key)
{
	if (key == W && v->p_d == 0 && v->p_y > 1 && \
					v->map[v->p_y - 1][v->p_x] != '1')
	{
		--v->p_y;
		pre_move_player(v);
	}
	if (key == W && v->p_d != 0)
	{
		v->p_d = 0;
		v->p_s = 0;
	}
	if (key == A && v->p_d == 1 && v->p_x > 1 && \
					v->map[v->p_y][v->p_x - 1] != '1')
	{
		--v->p_x;
		pre_move_player(v);
	}
	if (key == A && v->p_d != 1)
	{
		v->p_d = 1;
		v->p_s = 0;
	}
}

static void	sub_move_player_2(t_vars *v, int key)
{
	if (key == S && v->p_d == 2 && v->p_y < v->map_height - 2 && \
					v->map[v->p_y + 1][v->p_x] != '1')
	{
		++v->p_y;
		pre_move_player(v);
	}
	if (key == S && v->p_d != 2)
	{
		v->p_d = 2;
		v->p_s = 0;
	}
	if (key == D && v->p_d == 3 && v->p_x < v->map_width - 2 && \
					v->map[v->p_y][v->p_x + 1] != '1')
	{
		++v->p_x;
		pre_move_player(v);
	}
	if (key == D && v->p_d != 3)
	{
		v->p_d = 3;
		v->p_s = 0;
	}
}

void	move_player(t_vars *v, int key)
{
	if (v->is_moving_p == 0)
	{
		sub_move_player_1(v, key);
		sub_move_player_2(v, key);
	}
}
