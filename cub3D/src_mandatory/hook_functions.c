/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:55:19 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/18 00:29:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_vars *t, int key);
void	use_staff(t_vars *v, int key);

int	key_down_hook(int key, t_vars *v)
{
	if (key == left)
	{
		mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		v->p_d -= 0.04;
		if (v->p_d < 0)
			v->p_d += M_PI * 2;
		v->new_draw = 1;
	}
	if (key == right)
	{
		mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		v->p_d += 0.04;
		if (v->p_d > M_PI * 2)
			v->p_d -= M_PI * 2;
		v->new_draw = 1;
	}
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
	if (x < WINDOW_WIDTH / 2)
	{
		mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		v->p_d -= 0.06;
		if (v->p_d < 0)
			v->p_d += M_PI * 2;
		v->new_draw = 1;
	}
	if (x > WINDOW_WIDTH / 2)
	{
		mlx_mouse_move(v->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		v->p_d += 0.06;
		if (v->p_d > M_PI * 2)
			v->p_d -= M_PI * 2;
		v->new_draw = 1;
	}
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
