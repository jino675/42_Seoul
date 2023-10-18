/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:42:18 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/18 00:30:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_empty_line(t_vars *v, t_etc *e);

static void	get_parts(t_vars *v, t_etc *e)
{
	int		i;

	e->parts = ft_split(e->cur_line, ' ');
	if (e->parts == NULL)
		error_exit("Error", "memory allocation error!", v);
	i = 0;
	while (e->parts[i] != NULL)
		++i;
	if (i != 2)
		error_exit("Error", "invalid map (3)", v);
}

static int	sub_get_color_val(t_etc *e, char **temp)
{
	int	i;
	int	j;
	int	cur_val;

	e->color = 0;
	i = -1;
	while (temp[++i] != NULL && i < 3)
	{
		j = 0;
		while (temp[i][j] != '\0' && ft_isdigit(temp[i][j]) == 1)
			++j;
		if (temp[i][j] == '\0' && ft_strlen(temp[i]) < 4)
		{
			cur_val = ft_atoi(temp[i]);
			if (cur_val > 255)
				break ;
			e->color *= 256;
			e->color += cur_val;
		}
		else
			break ;
	}
	if (temp[i] != NULL || i < 3)
		return (-1);
	return (0);
}

static int	get_color_val(t_vars *v, t_etc *e)
{
	int		i;
	int		flag;
	char	**temp;

	if (ft_isdigit(e->parts[1][ft_strlen(e->parts[1]) - 1]) == 0)
		return (-1);
	temp = ft_split(e->parts[1], ',');
	if (temp == NULL)
		error_exit("Error", "memory allocation error!", v);
	flag = sub_get_color_val(e, temp);
	i = -1;
	while (temp[++i] != NULL)
		free(temp[i]);
	free(temp);
	if (flag == -1)
		return (-1);
	else
		return (0);
}

static int	add_information(t_vars *v, t_etc *e)
{
	get_parts(v, e);
	printf("%s %s %x %x\n", e->parts[0], e->parts[1], v->f_rgb, v->c_rgb);
	if (ft_strcmp(e->parts[0], "EA") == 0 && v->wall_path[0] == NULL)
		v->wall_path[0] = ft_strdup(e->parts[1]);
	else if (ft_strcmp(e->parts[0], "NO") == 0 && v->wall_path[1] == NULL)
		v->wall_path[1] = ft_strdup(e->parts[1]);
	else if (ft_strcmp(e->parts[0], "WE") == 0 && v->wall_path[2] == NULL)
		v->wall_path[2] = ft_strdup(e->parts[1]);
	else if (ft_strcmp(e->parts[0], "SO") == 0 && v->wall_path[3] == NULL)
		v->wall_path[3] = ft_strdup(e->parts[1]);
	else if (ft_strcmp(e->parts[0], "G") == 0 && v->wall_path[4] == NULL)
		v->wall_path[4] = ft_strdup(e->parts[1]);
	else if (ft_strcmp(e->parts[0], "F") == 0 && v->f_rgb == -1 && \
											get_color_val(v, e) == 0)
		v->f_rgb = e->color;
	else if (ft_strcmp(e->parts[0], "C") == 0 && v->c_rgb == -1 && \
											get_color_val(v, e) == 0)
		v->c_rgb = e->color;
	else
		return (-1);
	++e->d_cnt;
	return (0);
}

void	get_descriptor(t_vars *v, t_etc *e)
{
	while (e->d_cnt < 7)
	{
		e->cur_line = get_next_line(e->fd);
		if (e->cur_line == NULL)
			error_exit("Error", "invalid map (0)", v);
		e->cur_length = ft_strlen(e->cur_line);
		if (e->cur_line[e->cur_length - 1] == '\n')
		{
			e->cur_line[e->cur_length - 1] = '\0';
			--e->cur_length;
		}
		if (is_empty_line(v, e) == 0)
		{
			if (add_information(v, e) == -1)
				error_exit("Error", "invalid map (1)", v);
			free(e->parts[0]);
			free(e->parts[1]);
			free(e->parts);
		}
		free(e->cur_line);
	}
}
