/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:15:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:05:58 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/so_long_bonus.h"

unsigned long	myrand(unsigned long seed);

static int	check_enemy_dir(t_vars *v, int temp)
{
	if (temp == 0)
		if (v->e_y > 1 && v->map[v->e_y - 1][v->e_x] != '1')
			return (temp);
	if (temp == 1)
		if (v->e_x > 1 && v->map[v->e_y][v->e_x - 1] != '1')
			return (temp);
	if (temp == 2)
		if (v->e_y < v->map_height - 2 && \
					v->map[v->e_y + 1][v->e_x] != '1')
			return (temp);
	if (temp == 3)
		if (v->e_x < v->map_width - 2 && \
					v->map[v->e_y][v->e_x + 1] != '1')
			return (temp);
	return (-1);
}

static int	dir_to_player_1(t_vars *v)
{
	int	dif_x;
	int	dif_y;
	int	temp;

	dif_x = v->p_x - v->e_x;
	dif_y = v->p_y - v->e_y;
	if (abs(dif_x) > abs(dif_y))
		temp = dif_x;
	else
		temp = dif_y;
	if (temp == dif_y && dif_y < 0)
		temp = 0;
	else if (temp == dif_x && dif_x < 0)
		temp = 1;
	else if (temp == dif_y && dif_y > 0)
		temp = 2;
	else if (temp == dif_x && dif_x > 0)
		temp = 3;
	if (check_enemy_dir(v, temp) == -1)
		temp = -1;
	return (temp);
}

static int	dir_to_player_2(t_vars *v)
{
	int	dif_x;
	int	dif_y;
	int	temp;

	dif_x = v->p_x - v->e_x;
	dif_y = v->p_y - v->e_y;
	if (abs(dif_x) > abs(dif_y))
		temp = dif_y;
	else
		temp = dif_x;
	if (temp == dif_y && dif_y < 0)
		temp = 0;
	else if (temp == dif_x && dif_x < 0)
		temp = 1;
	else if (temp == dif_y && dif_y > 0)
		temp = 2;
	else if (temp == dif_x && dif_x > 0)
		temp = 3;
	if (check_enemy_dir(v, temp) == -1)
		temp = -1;
	return (temp);
}

static int	dir_random(t_vars *v)
{
	int	dir;

	while (1)
	{
		++v->r_seed;
		dir = myrand(v->r_seed) % 4;
		if (check_enemy_dir(v, dir) != -1)
			return (dir);
	}
}

int	find_enemy_dir(t_vars *v)
{
	int	res;
	int	mode;

	++v->r_seed;
	mode = myrand(v->r_seed) % 10;
	if (mode <= 5)
	{
		res = dir_to_player_1(v);
		if (res == -1)
		{
			res = dir_to_player_2(v);
			if (res == -1)
				res = dir_random(v);
		}
	}
	else if (mode > 5 && mode < 8)
		res = dir_random(v);
	else
		res = -1;
	return (res);
}
