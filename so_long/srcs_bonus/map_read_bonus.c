/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:35:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:05:56 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/so_long_bonus.h"

void	check_component(t_vars *v, t_etc *e);
void	check_can_clear(t_vars *v, t_etc *e);

static void	read_init(t_etc *e)
{
	int		i;

	i = -1;
	while (++i < MAP_HEIGHT_MAX + 1)
		e->temp_map[i] = NULL;
}

static void	check_open(t_vars *v, t_etc *e, int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
		error_exit("Error", "wrong arguments!", v, e);
	ptr = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (ptr == NULL || ptr != &av[1][ft_strlen(av[1]) - 4])
		error_exit("Error", "wrong extention!", v, e);
	v->file_name = ft_strdup("./asset/maps/");
	if (v->file_name == NULL)
		error_exit("Error", "memory allocation error!", v, e);
	if (ft_strattach(&v->file_name, av[1]) == -1)
		error_exit("Error", "memory allocation error!", v, e);
	e->fd = open(v->file_name, O_RDONLY);
	if (e->fd == -1)
		error_exit("Error", "open error!", v, e);
}

static void	read_check_form(t_vars *v, t_etc *e)
{
	int	i;

	i = -1;
	while (1)
	{
		e->cur_line = get_next_line(e->fd);
		if (e->cur_line == NULL)
			break ;
		v->map[++i] = e->cur_line;
		e->cur_length = ft_strlen(e->cur_line);
		if (e->cur_line[e->cur_length - 1] == '\n')
		{
			e->cur_line[e->cur_length - 1] = '\0';
			--e->cur_length;
		}
		if (i == 0)
			v->map_width = e->cur_length;
		if (v->map_width > MAP_WIDTH_MAX)
			error_exit("Error", "too large width!", v, e);
		if (i > 0 && e->cur_length != v->map_width)
			error_exit("Error", "ugly map!", v, e);
		if (++v->map_height == MAP_HEIGHT_MAX)
			error_exit("Error", "too large height!", v, e);
	}
	close(e->fd);
}

void	map_read(t_vars *v, int ac, char **av)
{
	t_etc	e;

	read_init(&e);
	check_open(v, &e, ac, av);
	read_check_form(v, &e);
	check_component(v, &e);
	check_can_clear(v, &e);
}
