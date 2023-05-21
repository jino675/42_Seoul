/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:51:22 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 21:30:56 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

static int	is_clear(t_etc *e)
{
	if (e->cur_e_count == 0 && e->cur_c_count == 0)
		return (1);
	else
		return (0);
}

static void	bfs(t_vars *v, t_etc *e, int x, int y)
{
	if (e->temp_map[y][x] == 'E')
		--e->cur_e_count;
	else if (e->temp_map[y][x] == 'C')
		--e->cur_c_count;
	e->temp_map[y][x] = 'S';
	if (is_clear(e) == 0 && x < v->map_width - 1 && \
			e->temp_map[y][x + 1] != '1' && e->temp_map[y][x + 1] != 'S')
		bfs(v, e, x + 1, y);
	if (is_clear(e) == 0 && x > 0 && \
			e->temp_map[y][x - 1] != '1' && e->temp_map[y][x - 1] != 'S')
		bfs(v, e, x - 1, y);
	if (is_clear(e) == 0 && y < v->map_height - 1 && \
			e->temp_map[y + 1][x] != '1' && e->temp_map[y + 1][x] != 'S')
		bfs(v, e, x, y + 1);
	if (is_clear(e) == 0 && y > 0 && \
			e->temp_map[y - 1][x] != '1' && e->temp_map[y - 1][x] != 'S')
		bfs(v, e, x, y - 1);
}

static void	init_bfs(t_vars *v, t_etc *e)
{
	int		i;

	i = -1;
	while (++i < v->map_height)
	{
		e->temp_map[i] = (char *)malloc(sizeof(char) * v->map_width + 1);
		if (e->temp_map[i] == NULL)
			error_exit("Error", "memory allocation error!", v, e);
		ft_strlcpy(e->temp_map[i], v->map[i], v->map_width + 1);
	}
	e->cur_e_count = v->e_count;
	e->cur_c_count = v->c_count;
}

void	check_can_clear(t_vars *v, t_etc *e)
{
	int	i;

	init_bfs(v, e);
	bfs(v, e, v->p_x, v->p_y);
	if (is_clear(e) == 0)
		error_exit("Error", "can't clear game!", v, e);
	i = -1;
	while (e->temp_map[++i] != NULL)
		free(e->temp_map[i]);
}
