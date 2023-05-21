/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:35:03 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 21:18:53 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

void	draw_player_idle(t_vars *v, int i, int j);
void	draw_player_walk(t_vars *v, int i, int j);
void	draw_enemy_idle(t_vars *v, int i, int j);
void	draw_enemy_walk(t_vars *v, int i, int j);
void	draw_etcs(t_vars *v, int i, int j);
void	move_enemy(t_vars *v);

static void	draw_background(t_vars *v)
{
	int		i;
	int		j;

	i = -1;
	while (++i < v->map_height + 1)
	{
		j = -1;
		while (++j < v->map_width)
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
							v->grass_img, j * MAP_UNIT, i * MAP_UNIT);
	}
}

static void	draw_all_component(t_vars *v)
{
	int		i;
	int		j;
	char	*nbr;

	draw_background(v);
	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (++j < v->map_width)
		{
			draw_etcs(v, i, j);
			draw_player_idle(v, i, j);
			draw_player_walk(v, i, j);
			draw_enemy_idle(v, i, j);
			draw_enemy_walk(v, i, j);
		}
	}
	nbr = ft_itoa(v->move_count);
	if (nbr == NULL)
		error_exit("Error", "memory allocation error", v, NULL);
	mlx_string_put(v->mlx_ptr, v->win_ptr, \
						5, v->map_height * MAP_UNIT, 0xFF0000, nbr);
	free(nbr);
}

int	loop_hook(t_vars *v)
{
	if (v->e_s == 0)
		move_enemy(v);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	draw_all_component(v);
	return (0);
}
