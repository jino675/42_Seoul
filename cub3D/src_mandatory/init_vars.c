/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:27:23 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 14:00:50 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sub_init_vars_1(t_vars *v)
{
	v->mlx_ptr = NULL;
	v->win_ptr = NULL;
	v->map = NULL;
	v->map_width = 0;
	v->map_height = 0;
	v->view = NULL;
	v->view_addr = NULL;
	v->f_rgb = -1;
	v->c_rgb = -1;
	v->img_path = NULL;
}

static void	sub_init_vars_2(t_vars *v)
{
	v->minimap = NULL;
	v->minimap_addr = NULL;
	v->minimap_x = 0;
	v->minimap_y = 0;
	v->minimap_d = 0;
	v->staff_state = 0;
	v->is_end = 0;
	v->is_moving = 0;
	v->is_door_changed = 0;
	v->is_new_draw = 1;
	v->is_change_direction = 0;
	v->is_mouse_show = 0;
	clock_gettime(CLOCK_REALTIME, &v->pre_time);
}

void	init_vars(t_vars *v)
{
	int	i;

	sub_init_vars_1(v);
	sub_init_vars_2(v);
	i = -1;
	while (++i < 5)
	{
		v->wall[i] = NULL;
		v->wall_path[i] = NULL;
		v->wall_addr[i] = NULL;
		v->staff[i] = NULL;
	}
	i = -1;
	while (++i < 6)
		v->minimap_parts[i] = NULL;
	i = -1;
	while (++i < 8)
		v->minimap_player[i] = NULL;
}

void	init_mlx_win(t_vars *v)
{
	v->mlx_ptr = mlx_init();
	if (v->mlx_ptr == NULL)
		error_exit("Error", "mlx_init error!", v);
	v->win_ptr = mlx_new_window(v->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
																"POOP 3D");
	if (v->win_ptr == NULL)
		error_exit("Error", "mlx_new_window error!", v);
	mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_mouse_hide();
}
