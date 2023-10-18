/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:30:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/18 00:43:00 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sub_draw_minimap(t_vars *v, int x, int y, int img_idx)
{
	int			i;
	int			j;
	int			buf;
	char		*ptr;
	const char	*part_line = mlx_get_data_addr(v->minimap_parts[img_idx], \
					&buf, &buf, &buf);

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < 30)
		{
			ptr = v->minimap_addr;
			ptr += (30 * y + i) * v->minimap_line_len;
			ptr += (30 * x + j) * (v->minimap_bpp / 8);
			*(unsigned int *)ptr = ((unsigned int *)part_line)[30 * i + j];
		}
	}
}

void	draw_minimap(t_vars *v)
{
	int	i;
	int	j;
	int	cur_x;
	int	cur_y;

	if (v->int_x == (int)v->p_x && v->int_y == (int)v->p_y)
		return ;
	i = -5;
	while (++i < 5)
	{
		cur_y = (int)v->p_y + i;
		j = -5;
		while (++j < 5)
		{
			cur_x = (int)v->p_x + j;
			if (cur_x == (int)v->p_x && cur_y == (int)v->p_y)
				sub_draw_minimap(v, j + 4, i + 4, 3);
			else if (cur_x >= 0 && cur_x < v->map_width && \
				cur_y >= 0 && cur_y < v->map_height)
			{
				if (v->map[cur_y][cur_x] == '1')
					sub_draw_minimap(v, j + 4, i + 4, 4);
				else if (v->map[cur_y][cur_x] == 'C')
					sub_draw_minimap(v, j + 4, i + 4, 0);
				else if (v->map[cur_y][cur_x] == '0'|| \
							v->map[cur_y][cur_x] == 'O')
					sub_draw_minimap(v, j + 4, i + 4, 1);
				else if (v->map[cur_y][cur_x] == 'G')
					sub_draw_minimap(v, j + 4, i + 4, 5);
				else
					sub_draw_minimap(v, j + 4, i + 4, 2);
			}
			else
				sub_draw_minimap(v, j + 4, i + 4, 2);
		}
	}
	v->int_x = (int)v->p_x;
	v->int_y = (int)v->p_y;
}