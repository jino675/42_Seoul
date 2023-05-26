/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:08:43 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:06:00 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/so_long_bonus.h"

int	find_enemy_dir(t_vars *v);

unsigned long	myrand(unsigned long seed)
{
	unsigned long	a;
	unsigned long	c;
	unsigned long	m;

	a = 1103515245;
	c = 12345;
	m = pow(2, 31);
	seed = (a * seed + c) % m;
	return (seed);
}

static void	pre_move_enemy(t_vars *v)
{
	v->e_s = 0;
	v->is_moving_e = 1;
	if (v->e_y == v->p_y && v->e_x == v->p_x)
		normal_exit(v);
}

static void	sub_move_enemy_1(t_vars *v, int dir)
{
	if (dir == 0 && v->e_y > 1 && v->map[v->e_y - 1][v->e_x] != '1')
	{
		--v->e_y;
		pre_move_enemy(v);
	}
	if (dir == 0 && v->e_d != 0)
	{
		v->e_d = 0;
		v->e_s = 0;
	}
	if (dir == 1 && v->e_x > 1 && v->map[v->e_y][v->e_x - 1] != '1')
	{
		--v->e_x;
		pre_move_enemy(v);
	}
	if (dir == 1 && v->e_d != 1)
	{
		v->e_d = 1;
		v->e_s = 0;
	}
}

static void	sub_move_enemy_2(t_vars *v, int dir)
{
	if (dir == 2 && v->e_y < v->map_height - 2 && \
							v->map[v->e_y + 1][v->e_x] != '1')
	{
		++v->e_y;
		pre_move_enemy(v);
	}
	if (dir == 2 && v->e_d != 2)
	{
		v->e_d = 2;
		v->e_s = 0;
	}
	if (dir == 3 && v->e_x < v->map_width - 2 && \
							v->map[v->e_y][v->e_x + 1] != '1')
	{
		++v->e_x;
		pre_move_enemy(v);
	}
	if (dir == 3 && v->e_d != 3)
	{
		v->e_d = 3;
		v->e_s = 0;
	}
}

void	move_enemy(t_vars *v)
{
	int	dir;

	dir = find_enemy_dir(v);
	if (dir == -1)
	{
		v->e_s = 0;
		return ;
	}
	sub_move_enemy_1(v, dir);
	sub_move_enemy_2(v, dir);
}
