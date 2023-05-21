/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:47:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 18:50:49 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

void	draw_player_idle(t_vars *v, int i, int j)
{
	if (i == v->p_y && j == v->p_x && v->is_moving_p == 0)
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->player_img_idle[v->p_d][v->p_s], j * MAP_UNIT, i * MAP_UNIT);
		if (++v->p_s == 4)
			v->p_s = 0;
	}
}

void	draw_player_walk(t_vars *v, int i, int j)
{
	if (i == v->p_y && j == v->p_x && v->is_moving_p == 1)
	{
		if (v->p_d == 0)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
						v->player_img_walk[v->p_d][v->p_s], j * MAP_UNIT, \
							(i + (4 - v->p_s) * 0.2) * MAP_UNIT);
		else if (v->p_d == 1)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
						v->player_img_walk[v->p_d][v->p_s], \
							(j + (4 - v->p_s) * 0.2) * MAP_UNIT, i * MAP_UNIT);
		else if (v->p_d == 2)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
						v->player_img_walk[v->p_d][v->p_s], j * MAP_UNIT, \
							(i - (4 - v->p_s) * 0.2) * MAP_UNIT);
		else if (v->p_d == 3)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
						v->player_img_walk[v->p_d][v->p_s], \
							(j - (4 - v->p_s) * 0.2) * MAP_UNIT, i * MAP_UNIT);
		if (++v->p_s == 4)
		{
			v->p_s = 0;
			v->is_moving_p = 0;
		}
	}
}

void	draw_enemy_idle(t_vars *v, int i, int j)
{
	if (i == v->e_y && j == v->e_x && v->is_moving_e == 0)
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->enemy_img_idle[v->e_d][v->e_s], j * MAP_UNIT, i * MAP_UNIT);
		if (++v->e_s == 4)
			v->e_s = 0;
	}
}

void	draw_enemy_walk(t_vars *v, int i, int j)
{
	if (i == v->e_y && j == v->e_x && v->is_moving_e == 1)
	{
		if (v->e_d == 0)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
		v->enemy_img_sword[v->e_d][v->e_s], \
			(j - 0.5) * MAP_UNIT, ((i - 0.5) + (4 - v->e_s) * 0.2) * MAP_UNIT);
		else if (v->e_d == 1)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
		v->enemy_img_sword[v->e_d][v->e_s], \
			((j - 0.5) + (4 - v->e_s) * 0.2) * MAP_UNIT, (i - 0.5) * MAP_UNIT);
		else if (v->e_d == 2)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
		v->enemy_img_sword[v->e_d][v->e_s], \
			(j - 0.5) * MAP_UNIT, ((i - 0.5) - (4 - v->e_s) * 0.2) * MAP_UNIT);
		else if (v->e_d == 3)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
		v->enemy_img_sword[v->e_d][v->e_s], \
			((j - 0.5) - (4 - v->e_s) * 0.2) * MAP_UNIT, (i - 0.5) * MAP_UNIT);
		if (++v->e_s == 4)
		{
			v->e_s = 1;
			v->is_moving_e = 0;
		}
	}
}

void	draw_etcs(t_vars *v, int i, int j)
{
	if (v->map[i][j] == '1')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
					v->rock_img, j * MAP_UNIT, i * MAP_UNIT);
	if (v->map[i][j] == 'C')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->heart_img, \
		j * MAP_UNIT + MAP_UNIT / 4, i * MAP_UNIT + MAP_UNIT / 4);
	if (v->map[i][j] == 'E')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
					v->sign_img, j * MAP_UNIT, i * MAP_UNIT);
}
