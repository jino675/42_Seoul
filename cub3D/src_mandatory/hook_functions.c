/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:55:19 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/20 17:26:57 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_vars *t, int key);
void	use_staff(t_vars *v, int key);
void	change_direction(t_vars *v, int mode, int val);

int	key_down_hook(int key, t_vars *v)
{
	if (key == P)
	{
		if (v->is_mouse_show == 0)
		{
			mlx_mouse_show();
			v->is_mouse_show = 1;
		}
		else
		{
			mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
			mlx_mouse_hide();
			v->is_mouse_show = 0;
		}
	}
	change_direction(v, 0, key);
	move_player(v, key);
	return (0);
}

int	mouse_click_hook(int button, int x, int y, t_vars *v)
{
	x = 0;
	y = 0;
	use_staff(v, button);
	return (0);
}

int	mouse_move_hook(int x, int y, t_vars *v)
{
	y = 0;
	change_direction(v, 1, x);
	return (0);
}

int	key_up_hook(int key, t_vars *v)
{
	if (key == Esc)
		normal_exit(NULL, v);
	return (0);
}

int	exit_hook(t_vars *v)
{
	normal_exit(NULL, v);
	return (0);
}
