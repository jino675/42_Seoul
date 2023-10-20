/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_staff_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:38:55 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/20 18:39:10 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_goal(t_vars *v, double x, double y)
{
	if ((ceil(x) - STAFF_THRES <= x && x < ceil(x) - MOVING_THRES && \
		(int)(v->p_d / M_PI_2) == 0 && \
		v->map[(int)floor(y)][(int)ceil(x)] == 'G') || \
		(floor(x) + MOVING_THRES < x && x <= floor(x) + STAFF_THRES && \
		(int)(v->p_d / M_PI_2) == 2 && \
		v->map[(int)floor(y)][(int)floor(x) - 1] == 'G') || \
		(ceil(y) - STAFF_THRES <= y && y < ceil(y) - MOVING_THRES && \
		(int)(v->p_d / M_PI_2) == 1 && \
		v->map[(int)ceil(y)][(int)floor(x)] == 'G') || \
		(floor(y) + MOVING_THRES < y && y <= floor(y) + STAFF_THRES && \
		(int)(v->p_d / M_PI_2) == 3 && \
		v->map[(int)floor(y) - 1][(int)floor(x)] == 'G'))
		v->is_end = 1;
}
