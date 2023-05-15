/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:35:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/08 22:40:19 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

typedef struct s_etc
{
	int		is_p;
	int		is_e;
	int		is_c;
	int		fd;
	int		cur_length;
	char	*cur_line;
}	t_etc;


// static void	map_get_height(t_vars *v, t_etc *e)
// {
// 	int	i;

// 	e->fd = open("../asset/maps/map_default.ber", O_RDONLY);
// 	if (e->fd == -1)
// 		error_exit(NULL, "open error!");
// 	v->map_height = 0;
// 	i = -1;
// 	while (1)
// 	{
// 		e->cur_line = get_next_line(fd);
// 		if (e->cur_line == NULL)
// 			break ;
// 		++v->map_height;
// 		temp[i] = e->cur_line;
// 	}
// 	close(e->fd);
// 	v->map = (char **)malloc(sizeof(char *) * v->map_height);
// 	if (v->map == NULL)
// 		error_exit(NULL, "memory allocation error!", v);
// }

static void	map_read_init(t_vars *v, t_etc *e)
{
	int	i;

	e->fd = open("../asset/maps/map_default.ber", O_RDONLY);
	if (e->fd == -1)
		error_exit(NULL, "open error!");
	v->map_height = 0;
	i = -1;
	while (++i < MAP_HEIGHT_MAX + 1)
		v->map[i] = NULL;
	e->is_p = 0;
	e->is_e = 0;
	e->is_c = 0;
}

static void	map_check_form(t_vars *v, t_etc *e)
{
	int	i;

	i = 0;
	while (1)
	{
		e->cur_line = get_next_line(e->fd);
		if (e->cur_line == NULL)
			break ;
		if (cur_line[e->cur_length - 1] == '\n')
			cur_line[e->cur_length - 1] = '\0';
		e->cur_length = ft_strlen(e->cur_line);
		if (i == 0)
			v->map_width = e->cur_length;
		else if (i > 0 && e->cur_length != v->map_width)
			error_exit(NULL, "wrong map!", v);
		v->map[i] = e->cur_line;
		++v->map_height;
		if (v->map_height > MAP_HEIGHT_MAX)
			error_exit(NULL, "wrong map!", v);
		++i;
	}
	close(fd);
}

static void	sub_map_check(t_vars *v, t_etc *e, int i, int j)
{
	if (i == 0 || i == v->map_height - 1 || j == 0 || j == v->map_width - 1)
		if (v->map[i][j] != '1')
			error_exit(NULL, "wrong map!", v);
	if (v->map[i][j] == 'P')
	{
		++e->is_p;
		v->p_x = j;
		v->p_y = i;
		v->map[i][j] = '0';
	}
	else if (v->map[i][j] == 'E')
	{
		++e->is_e;
		v->e_x = j;
		v->e_y = i;
		v->map[i][j] = '0';
	}
	else if (v->map[i][j] == 'C')
		++e->is_c;
	else if (v->map[i][j] != '0' && v->map[i][j] != '1')
		error_exit(NULL, "wrong map!", v);
}

static void	map_check(t_vars *v, t_etc *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (v->map[i][++j] != NULL)
			sub_map_check(v, e, i, j);
	}
	if (e->is_p != 1 || e->is_e != 1 || e->is_c == 0)
		error_exit(NULL, "wrong map!", v);
}

void	map_read(t_vars *v)
{
	int		i;
	t_etc	e;

	map_read_init(v, &e);
	map_check_form(v, &e);
	map_check_component(v, &e);
}