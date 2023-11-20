/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:43:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/21 15:30:11 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_xdir(t_vars *v, t_cal *c);
int	check_ydir(t_vars *v, t_cal *c);

static void	get_add_val(t_vars *v, t_cal *c)
{
	if (0 <= c->cur_d && c->cur_d < M_PI_2)
	{
		c->add_x = ceil(v->p_x) - v->p_x;
		c->add_y = ceil(v->p_y) - v->p_y;
	}
	else if (M_PI_2 <= c->cur_d && c->cur_d < M_PI)
	{
		c->add_x = floor(v->p_x) - v->p_x;
		c->add_y = ceil(v->p_y) - v->p_y;
	}
	else if (M_PI <= c->cur_d && c->cur_d < M_PI + M_PI_2)
	{
		c->add_x = floor(v->p_x) - v->p_x;
		c->add_y = floor(v->p_y) - v->p_y;
	}
	else if (M_PI + M_PI_2 <= c->cur_d && c->cur_d < M_PI * 2)
	{
		c->add_x = ceil(v->p_x) - v->p_x;
		c->add_y = floor(v->p_y) - v->p_y;
	}
}

static void	get_img_line(t_vars *v, t_cal *c)
{
	double	dis_1;
	double	dis_2;

	get_add_val(v, c);
	while (1)
	{
		if (fabs(sin(c->cur_d)) <= 0.001)
		{
			if (check_xdir(v, c) == 1)
				return ;
		}
		else if (fabs(cos(c->cur_d)) <= 0.001)
		{
			if (check_ydir(v, c) == 1)
				return ;
		}
		else
		{
			dis_1 = c->add_x / cos(c->cur_d);
			dis_2 = c->add_y / sin(c->cur_d);
			if ((dis_1 < dis_2 && check_xdir(v, c) == 1) || \
				(dis_1 >= dis_2 && check_ydir(v, c) == 1))
				return ;
		}
	}
}

void	draw_view(t_vars *v)
{
	t_cal	c;
	int		i;
	int		j;
	char	*ptr;

	c.wall_line = (unsigned int *)ft_calloc(WINDOW_HEIGHT, \
										sizeof(unsigned int));
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		c.cur_d = v->p_d + atan(((double)(i * 2 / sqrt(3)) / WINDOW_WIDTH) \
															- (1 / sqrt(3)));
		if (c.cur_d > M_PI * 2)
			c.cur_d -= M_PI * 2;
		else if (c.cur_d < 0)
			c.cur_d += M_PI * 2;
		get_img_line(v, &c);
		j = -1;
		while (++j < WINDOW_HEIGHT)
		{
			ptr = v->view_addr + (j * WINDOW_WIDTH + i) * 4;
			*(unsigned int *)ptr = c.wall_line[j];
		}
	}
	free(c.wall_line);
}
