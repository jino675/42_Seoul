/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:53 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_leak(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_vars	v;

	atexit(check_leak);
	init_vars(&v);
	map_read(&v, ac, av);
	init_mlx_win(&v);
	load_images(&v);
	mlx_hook(v.win_ptr, 2, 0, key_down_hook, &v);
	mlx_hook(v.win_ptr, 3, 0, key_up_hook, &v);
	mlx_hook(v.win_ptr, 4, 0, mouse_click_hook, &v);
	mlx_hook(v.win_ptr, 6, 0, mouse_move_hook, &v);
	mlx_hook(v.win_ptr, 17, 0, exit_hook, &v);
	mlx_loop_hook(v.mlx_ptr, loop_hook, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
