/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:27:23 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:18:35 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/so_long_bonus.h"

static void	sub_init_vars_1(t_vars *v)
{
	int	i;

	v->mlx_ptr = NULL;
	v->win_ptr = NULL;
	v->file_name = NULL;
	i = -1;
	while (++i < MAP_HEIGHT_MAX + 1)
		v->map[i] = NULL;
	v->map_width = 0;
	v->map_height = 0;
	v->rock_img = NULL;
	v->grass_img = NULL;
	v->heart_img = NULL;
	v->sign_img = NULL;
	v->img_path = NULL;
	v->move_str = NULL;
}

static void	sub_init_vars_2(t_vars *v)
{
	v->move_count = 0;
	v->is_moving_p = 0;
	v->p_x = 1;
	v->p_y = 1;
	v->p_d = 2;
	v->p_s = 1;
	v->is_moving_e = 0;
	v->e_x = 1;
	v->e_y = 1;
	v->e_d = 2;
	v->e_s = 1;
	v->r_seed = 0;
	v->p_count = 0;
	v->e_count = 0;
	v->c_count = 0;
}

void	init_vars(t_vars *v)
{
	int	i;
	int	j;

	sub_init_vars_1(v);
	sub_init_vars_2(v);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			v->player_img_walk[i][j] = NULL;
			v->player_img_idle[i][j] = NULL;
			v->enemy_img_sword[i][j] = NULL;
			v->enemy_img_idle[i][j] = NULL;
		}
	}
	v->move_str = ft_strdup("total move : ");
	if (v->move_str == NULL)
		error_exit("Error", "memory allocation error!", v, NULL);
}

void	init_mlx_win(t_vars *v)
{
	v->mlx_ptr = mlx_init();
	if (v->mlx_ptr == NULL)
		error_exit("Error", "mlx_init error!", v, NULL);
	v->win_ptr = mlx_new_window(v->mlx_ptr, MAP_UNIT * v->map_width, \
							MAP_UNIT * (v->map_height + 1), "POOP GAME");
	if (v->win_ptr == NULL)
		error_exit("Error", "mlx_new_window error!", v, NULL);
}
