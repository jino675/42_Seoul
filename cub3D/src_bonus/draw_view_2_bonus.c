/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:43:40 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_wall(t_vars *v, int x, int y);
int	get_wall_idx(t_vars *v, int x, int y, int idx);

static void	distract_img_line(t_vars *v, t_cal *c)
{
	int			i;
	double		pixel_idx;
	char		*ptr;
	const int	new_size = (int)(WALL_DEFAULT_SIZE / c->distance);

	i = -1;
	if (new_size > WINDOW_HEIGHT)
		pixel_idx = (((double)(new_size - WINDOW_HEIGHT) / 2) / new_size) * \
															WALL_DEFAULT_SIZE;
	else
		pixel_idx = 0;
	while (++i < WINDOW_HEIGHT)
	{
		if (i < (WINDOW_HEIGHT - new_size) / 2)
			c->wall_line[i] = (unsigned int)v->c_rgb;
		else if (i < (WINDOW_HEIGHT - new_size) / 2 + new_size)
		{
			ptr = v->wall_addr[c->wall_idx];
			ptr += (int)round(pixel_idx) * WALL_DEFAULT_SIZE * 4;
			c->wall_line[i] = *(unsigned int *)(ptr + c->wall_line_idx * 4);
			pixel_idx += c->distance;
		}
		else
			c->wall_line[i] = (unsigned int)v->f_rgb;
	}
}

static int	is_wall_xdir(t_vars *v, t_cal *c)
{
	if (c->add_x < 0)
		c->cur_x = (int)round(v->p_x + c->add_x - 1);
	else
		c->cur_x = (int)round(v->p_x + c->add_x);
	c->cur_y = (int)floor(v->p_y + (c->add_x * tan(c->cur_d)));
	if (c->cur_x < 0 || c->cur_x >= v->map_width || \
		c->cur_y < 0 || c->cur_y >= v->map_height)
		return (0);
	if (is_wall(v, c->cur_x, c->cur_y) == 0)
		return (0);
	c->distance = (c->add_x / cos(c->cur_d)) * sin(M_PI_2 + v->p_d - c->cur_d);
	if (c->add_x > 0)
	{
		c->wall_idx = get_wall_idx(v, c->cur_x, c->cur_y, 2);
		c->wall_line_idx = (ceil(v->p_y + (c->add_x * tan(c->cur_d))) - \
				(v->p_y + (c->add_x * tan(c->cur_d)))) * WALL_DEFAULT_SIZE;
	}
	else
	{
		c->wall_idx = get_wall_idx(v, c->cur_x, c->cur_y, 0);
		c->wall_line_idx = ((v->p_y + (c->add_x * tan(c->cur_d))) - \
				floor(v->p_y + (c->add_x * tan(c->cur_d)))) * WALL_DEFAULT_SIZE;
	}
	return (1);
}

static int	is_wall_ydir(t_vars *v, t_cal *c)
{
	c->cur_x = (int)floor(v->p_x + (c->add_y / tan(c->cur_d)));
	if (c->add_y < 0)
		c->cur_y = (int)round(v->p_y + c->add_y - 1);
	else
		c->cur_y = (int)round(v->p_y + c->add_y);
	if (c->cur_x < 0 || c->cur_x >= v->map_width || \
		c->cur_y < 0 || c->cur_y >= v->map_height)
		return (0);
	if (is_wall(v, c->cur_x, c->cur_y) == 0)
		return (0);
	c->distance = (c->add_y / sin(c->cur_d)) * sin(M_PI_2 + v->p_d - c->cur_d);
	if (c->add_y > 0)
	{
		c->wall_idx = get_wall_idx(v, c->cur_x, c->cur_y, 1);
		c->wall_line_idx = ((v->p_x + (c->add_y / tan(c->cur_d))) - \
				floor(v->p_x + (c->add_y / tan(c->cur_d)))) * WALL_DEFAULT_SIZE;
	}
	else
	{
		c->wall_idx = get_wall_idx(v, c->cur_x, c->cur_y, 3);
		c->wall_line_idx = (ceil(v->p_x + (c->add_y / tan(c->cur_d))) - \
				(v->p_x + (c->add_y / tan(c->cur_d)))) * WALL_DEFAULT_SIZE;
	}
	return (1);
}

int	check_xdir(t_vars *v, t_cal *c)
{
	if (c->add_x * tan(c->cur_d) < v->map_height)
	{
		if (is_wall_xdir(v, c) == 1)
		{
			distract_img_line(v, c);
			return (1);
		}
	}
	if (c->add_x < 0)
		c->add_x += -1;
	else
		c->add_x += 1;
	return (0);
}

int	check_ydir(t_vars *v, t_cal *c)
{
	if (c->add_y / tan(c->cur_d) < v->map_width)
	{
		if (is_wall_ydir(v, c) == 1)
		{
			distract_img_line(v, c);
			return (1);
		}
	}
	if (c->add_y < 0)
		c->add_y += -1;
	else
		c->add_y += 1;
	return (0);
}
