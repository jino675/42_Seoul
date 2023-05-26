/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:53 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:05:49 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_vars	v;

	init_vars(&v);
	map_read(&v, ac, av);
	init_mlx_win(&v);
	load_images(&v);
	mlx_hook(v.win_ptr, 2, 0, key_down_hook, &v);
	mlx_hook(v.win_ptr, 3, 0, key_up_hook, &v);
	mlx_hook(v.win_ptr, 17, 0, exit_hook, &v);
	mlx_loop_hook(v.mlx_ptr, loop_hook, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
