/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:30:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sub_draw_parts(t_vars *v, int x, int y, int img_idx)
{
	int			i;
	int			j;
	int			buf;
	char		*ptr;
	const char	*part_line = mlx_get_data_addr(v->minimap_parts[img_idx], \
					&buf, &buf, &buf);

	i = -1;
	while (++i < MINIMAP_PART_SIZE)
	{
		j = -1;
		while (++j < MINIMAP_PART_SIZE)
		{
			ptr = v->minimap_addr;
			ptr += (MINIMAP_PART_SIZE * y + i) * MINIMAP_SIZE * 4;
			ptr += (MINIMAP_PART_SIZE * x + j) * 4;
			*(unsigned int *)ptr = \
					((unsigned int *)part_line)[MINIMAP_PART_SIZE * i + j];
		}
	}
}

static void	sub_draw_player(t_vars *v, int x, int y)
{
	int			i;
	int			j;
	int			buf;
	char		*ptr;
	const char	*part_line = mlx_get_data_addr(v->minimap_player[v->minimap_d], \
															&buf, &buf, &buf);

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < 30)
		{
			ptr = v->minimap_addr;
			ptr += (MINIMAP_PART_SIZE * y + i) * MINIMAP_SIZE * 4;
			ptr += (MINIMAP_PART_SIZE * x + j) * 4;
			*(unsigned int *)ptr = \
						((unsigned int *)part_line)[MINIMAP_PART_SIZE * i + j];
		}
	}
}

static int	get_direction(t_vars *v)
{
	const int	val = (int)(v->p_d / (M_PI_4 / 2));

	if ((0 <= val && val < 1) || (15 <= val && val < 16))
		return (0);
	else if (1 <= val && val < 3)
		return (1);
	else if (3 <= val && val < 5)
		return (2);
	else if (5 <= val && val < 7)
		return (3);
	else if (7 <= val && val < 9)
		return (4);
	else if (9 <= val && val < 11)
		return (5);
	else if (11 <= val && val < 13)
		return (6);
	else if (13 <= val && val < 15)
		return (7);
	return (-1);
}

static void	sub_draw_minimap(t_vars *v, int i, int j)
{
	int	cur_x;
	int	cur_y;

	cur_x = v->minimap_x + j;
	cur_y = v->minimap_y + i;
	if (cur_x == v->minimap_x && cur_y == v->minimap_y)
		sub_draw_player(v, j + 4, i + 4);
	else if (cur_x >= 0 && cur_x < v->map_width && \
		cur_y >= 0 && cur_y < v->map_height)
	{
		if (v->map[cur_y][cur_x] == '1')
			sub_draw_parts(v, j + 4, i + 4, 3);
		else if (v->map[cur_y][cur_x] == 'C')
			sub_draw_parts(v, j + 4, i + 4, 0);
		else if (v->map[cur_y][cur_x] == '0')
			sub_draw_parts(v, j + 4, i + 4, 5);
		else if (v->map[cur_y][cur_x] == 'O')
			sub_draw_parts(v, j + 4, i + 4, 1);
		else if (v->map[cur_y][cur_x] == 'G')
			sub_draw_parts(v, j + 4, i + 4, 4);
		else
			sub_draw_parts(v, j + 4, i + 4, 2);
	}
	else
		sub_draw_parts(v, j + 4, i + 4, 2);
}

void	draw_minimap(t_vars *v)
{
	int	i;
	int	j;

	if (v->minimap_x == (int)v->p_x && v->minimap_y == (int)v->p_y && \
		v->minimap_d == get_direction(v) && v->is_door_changed == 0)
		return ;
	v->minimap_x = (int)v->p_x;
	v->minimap_y = (int)v->p_y;
	v->minimap_d = get_direction(v);
	v->is_door_changed = 0;
	i = -5;
	while (++i < 5)
	{
		j = -5;
		while (++j < 5)
		{
			sub_draw_minimap(v, i, j);
		}
	}
}
