/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_direction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:05:18 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:24 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	change_direction(t_vars *v, int mode, int val)
{
	if ((mode == 0 && val == left) || \
		(v->is_mouse_show == 0 && mode == 1 && val < WINDOW_WIDTH / 2))
	{
		mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		v->is_change_direction = -1;
		v->is_new_draw = 1;
	}
	else if ((mode == 0 && val == right) || \
			(v->is_mouse_show == 0 && mode == 1 && val > WINDOW_WIDTH / 2))
	{
		mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		v->is_change_direction = 1;
		v->is_new_draw = 1;
	}
}
