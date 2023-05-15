/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:53 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/08 22:08:08 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

int	key_down_hook(int key, t_vars *v)
{
	ft_printf("K Down : key code = %d\n", key);
	v->mlx_ptr += 0;
	v->win_ptr += 0;
	return (0);
}

int	key_up_hook(int key, t_vars *v)
{
	ft_printf("K Up : key code = %d\n", key);
	v->mlx_ptr += 0;
	v->win_ptr += 0;
	return (0);
}

int	mouse_down_hook(int button, int x, int y, t_vars *v)
{
	ft_printf("M Down : button code = %d, x = %d, y = %d\n", button, x, y);
	v->mlx_ptr += 0;
	v->win_ptr += 0;
	v->is_button = 1;
	v->cur_button = button;
	return (0);
}

int	mouse_up_hook(int button, int x, int y, t_vars *v)
{
	ft_printf("M Up : button code = %d, x = %d, y = %d\n", button, x, y);
	v->mlx_ptr += 0;
	v->win_ptr += 0;
	v->is_button = 0;
	v->cur_button = 0;
	return (0);
}

int	mouse_move_hook(int x, int y, t_vars *v)
{
	ft_printf("M Move : x = %d, y = %d\n", x, y);
	if (v->is_button == 1 && v->cur_button == Left)
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, x, y, 0xFFFFFF);
	x += 0;
	y += 0;
	v->mlx_ptr += 0;
	v->win_ptr += 0;
	return (0);
}

int	loop_hook(t_vars *v)
{
	// ft_printf("Default : *****\n");
	v->mlx_ptr += 0;
	v->win_ptr += 0;
	return (0);
}

void	error_exit(char *msg_1, char *msg_2, t_vars *v)
{
	if (msg_1 != NULL)
		ft_printf("%s: ", msg_1);
	if (msg_2 != NULL)
		ft_printf("%s\n", msg_2);
	i = -1;
	while (v->map[++i] != NULL)
		free(v->map[i]);
}

void	map_get_height(t_vars *v)
{
	int		i;
	int		fd;
	int		cur_length;
	char	*cur_line;

	fd = open("../asset/maps/map_default.ber", O_RDONLY);
	if (fd == -1)
		error_exit(NULL, "open error!");
	v->map_height = 0;
	i = 0;
	while (1)
	{
		cur_line = get_next_line(fd);
		if (cur_line == NULL)
			break ;
		++v->map_height;
	}
	close(fd);
	v->map = (char **)malloc(sizeof(char *) * v->map_height);
	if (v->map == NULL)
		error_exit(NULL, "memory allocation error!", v);
}

void	map_check(t_vars *v)
{
	int	is_p;
	int	is_e;
	int	is_c;
	int	i;
	int	j;

	is_p = 0;
	is_e = 0;
	is_c = 0;
	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (v->map[i][++j] != NULL)
		{
			if ((i == 0 || i == v->map_height - 1) && v->map[i][j] != '1')
				error_exit(NULL, "wrong map!", v);
			else if ((j == 0 || j == v->map_width - 1) && v->map[i][j] != '1')
				error_exit(NULL, "wrong map!", v);
			if (v->map[i][j] == 'P')
				++is_p;
			else if (v->map[i][j] == 'E')
				++is_e;
			else if (v->map[i][j] == 'C')
				++is_c;
		}
	}
	
}

void	map_read(t_vars *v)
{
	int		i;
	int		fd;
	int		cur_length;
	char	*cur_line;

	map_get_height(v);
	fd = open("../asset/maps/map_default.ber", O_RDONLY);
	if (fd == -1)
		error_exit(NULL, "open error!");
	i = 0;
	while (1)
	{
		cur_line = get_next_line(fd);
		if (cur_line == NULL)
			break ;
		if (cur_line[cur_length - 1] == '\n')
			cur_line[cur_length - 1] = '\0';
		cur_length = ft_strlen(cur_line);
		if (i > 0 && cur_length != v->map_width)
			error_exit(NULL, "wrong map!", v);
		if (i == 0)
			v->map_width = cur_length;
		v->map[i] = cur_line;
	}
	map_check(v);
}

int	main(void)
{
	t_vars	v;

	v.is_button = 0;
	v.cur_button = 0;
	v.mlx_ptr = mlx_init();
	if (v.mlx_ptr == NULL)
		error_exit(NULL, "mlx_init error!");
	v.win_ptr = mlx_new_window(v.mlx_ptr, 1920, 1080, "Bell and Run!");
	if (v.win_ptr == NULL)
		error_exit(NULL, "mlx_new_window error!");
	mlx_hook(v.win_ptr, 2, 0, key_down_hook, &v);
	mlx_hook(v.win_ptr, 3, 0, key_up_hook, &v);
	mlx_hook(v.win_ptr, 4, 0, mouse_down_hook, &v);
	mlx_hook(v.win_ptr, 5, 0, mouse_up_hook, &v);
	mlx_hook(v.win_ptr, 6, 0, mouse_move_hook, &v);
	mlx_loop_hook(v.mlx_ptr, loop_hook, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}