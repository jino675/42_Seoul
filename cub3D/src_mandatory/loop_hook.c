/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:35:03 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/21 19:31:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_frame(t_vars *v, int frame_per_sec)
{
	struct timespec	cur;
	long long		dif;

	clock_gettime(CLOCK_REALTIME, &cur);
	dif = (cur.tv_sec - v->pre_time.tv_sec) * 1000000000 + \
		(cur.tv_nsec - v->pre_time.tv_nsec);
	if (dif < 1000000000 / frame_per_sec)
	{
		v->pre_time = cur;
		return (0);
	}
	return (1);
}

static void	check_things(t_vars *v)
{
	if (v->is_new_draw == 1)
	{
		if (v->is_change_direction != 0)
		{
			v->p_d += 0.05 * v->is_change_direction;
			if (v->p_d > M_PI * 2)
				v->p_d -= M_PI * 2;
			else if (v->p_d < 0)
				v->p_d += M_PI * 2;
			v->is_change_direction = 0;
		}
		draw_view(v);
		draw_minimap(v);
		v->is_new_draw = 0;
	}
	if (v->is_moving == 1)
	{
		if (++v->staff_state == 5)
		{
			if (v->is_end == 1)
				normal_exit("Clear!", v);
			v->staff_state = 0;
			v->is_moving = 0;
		}
	}
}

int	loop_hook(t_vars *v)
{
	if (check_frame(v, 60) == 0)
		return (0);
	if (v->is_new_draw == 1 || v->is_moving == 1)
	{
		check_things(v);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->view, 0, 0);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->minimap, 30, 420);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
											v->staff[v->staff_state], 400, 220);
	}
	return (0);
}
