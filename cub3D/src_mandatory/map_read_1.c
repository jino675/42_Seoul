/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:35:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/20 19:01:29 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_descriptor(t_vars *v, t_etc *e);
void	get_map(t_vars *v, t_etc *e);
void	check_map(t_vars *v);

int	is_empty_line(t_vars *v, t_etc *e)
{
	int		res;
	char	*temp;

	temp = ft_strtrim(e->cur_line, " ");
	if (temp == NULL)
		error_exit("Error", "memory allocation error!", v);
	if (temp[0] == '\0')
		res = 1;
	else
		res = 0;
	free(temp);
	return (res);
}

static void	read_init(t_vars *v, t_etc *e)
{
	e->fd = -1;
	e->cur_length = 0;
	e->cur_line = NULL;
	e->d_cnt = 0;
	e->parts = NULL;
	e->color = 0;
	e->is_map = 0;
	e->size = 10;
	e->top = -1;
	e->map = (char **)ft_calloc(e->size, sizeof(char *));
	if (e->map == NULL)
		error_exit("Error", "memory allocation error!", v);
	e->max_len = 0;
}

static void	check_open(t_vars *v, t_etc *e, int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
		error_exit("Error", "wrong arguments!", v);
	ptr = ft_strnstr(av[1], ".cub", ft_strlen(av[1]));
	if (ptr == NULL || ptr != &av[1][ft_strlen(av[1]) - 4])
		error_exit("Error", "wrong extention!", v);
	v->map_path = ft_strdup("./asset/maps/");
	if (v->map_path == NULL)
		error_exit("Error", "memory allocation error!", v);
	if (ft_strattach(&v->map_path, av[1]) == -1)
		error_exit("Error", "memory allocation error!", v);
	e->fd = open(v->map_path, O_RDONLY);
	if (e->fd == -1)
		error_exit("Error", "open error!", v);
}

static void	print_information(t_vars *v)
{
	int	i;

	i = -1;
	while (++i < 5)
		printf("%s\n", v->wall_path[i]);
	printf("%x\n", v->f_rgb);
	printf("%x\n", v->c_rgb);
	i = -1;
	while (v->map[++i] != NULL)
		printf("%s\n", v->map[i]);
}

void	map_read(t_vars *v, int ac, char **av)
{
	t_etc	e;

	read_init(v, &e);
	check_open(v, &e, ac, av);
	get_descriptor(v, &e);
	get_map(v, &e);
	print_information(v);
	check_map(v);
}
