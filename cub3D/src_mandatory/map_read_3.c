/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:51:22 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/20 21:09:18 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_empty_line(t_vars *v, t_etc *e);

static void	add_line_to_map(t_vars *v, t_etc *e)
{
	int		i;
	char	**temp;

	if (e->top == e->size - 2)
	{
		temp = (char **)ft_calloc(e->size * 2, sizeof(char *));
		if (temp == NULL)
			error_exit("Error", "memory allocation error!", v);
		i = -1;
		while (++i < e->size - 1)
			temp[i] = e->map[i];
		free(e->map);
		e->map = temp;
		e->size *= 2;
	}
	e->map[++e->top] = e->cur_line;
}

static void	trim_map_line(t_vars *v, t_etc *e)
{
	int		flag;
	char	*temp;

	flag = 0;
	if (e->cur_line[0] == ' ')
	{
		flag = 1;
		e->cur_line[0] = 'a';
	}
	temp = ft_strtrim(e->cur_line, " ");
	if (temp == NULL)
		error_exit("Error", "memory allocation error!", v);
	if (flag == 1)
		temp[0] = ' ';
	free(e->cur_line);
	e->cur_line = temp;
}

static void	normalize_map(t_vars *v, t_etc *e)
{
	int	i;

	v->map = (char **)ft_calloc(e->top + 2, sizeof(char *));
	if (v->map == NULL)
		error_exit("Error", "memory allocation error!", v);
	i = -1;
	while (++i < e->top + 1)
	{
		e->cur_length = ft_strlen(e->map[i]);
		if (e->cur_length < e->max_len)
		{
			e->cur_line = (char *)ft_calloc(e->max_len + 1, sizeof(char));
			if (e->cur_line == NULL)
				error_exit("Error", "memory allocation error!", v);
			ft_memset(e->cur_line, ' ', e->max_len);
			ft_memcpy(e->cur_line, e->map[i], e->cur_length);
			free(e->map[i]);
			e->map[i] = e->cur_line;
		}
		v->map[i] = e->map[i];
	}
	free(e->map);
}

static void	sub_get_map(t_vars *v, t_etc *e)
{
	if (e->is_map == 0)
	{
		if (is_empty_line(v, e) == 1)
			free(e->cur_line);
		else
			e->is_map = 1;
	}
	if (e->is_map == 1)
	{
		if (is_empty_line(v, e) == 1)
			error_exit("Error", "invalid map (2)", v);
		else
		{
			trim_map_line(v, e);
			e->cur_length = ft_strlen(e->cur_line);
			if (e->cur_length > e->max_len)
				e->max_len = e->cur_length;
			add_line_to_map(v, e);
		}
	}
}

void	get_map(t_vars *v, t_etc *e)
{
	while (1)
	{
		e->cur_line = get_next_line(e->fd);
		if (e->cur_line == NULL)
			break ;
		e->cur_length = ft_strlen(e->cur_line);
		if (e->cur_line[e->cur_length - 1] == '\n')
		{
			e->cur_line[e->cur_length - 1] = '\0';
			--e->cur_length;
		}
		sub_get_map(v, e);
	}
	close(e->fd);
	normalize_map(v, e);
	v->map_width = e->max_len;
	v->map_height = e->top + 1;
}
