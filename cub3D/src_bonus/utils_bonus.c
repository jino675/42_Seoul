/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:23 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:39 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_v(t_vars *v)
{
	int	i;

	if (v->win_ptr != NULL)
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	i = -1;
	while (++i < 8)
	{
		if (i < 5 && v->wall[i] != NULL)
			mlx_destroy_image(v->mlx_ptr, v->wall[i]);
		if (i < 5 && v->staff[i] != NULL)
			mlx_destroy_image(v->mlx_ptr, v->staff[i]);
		if (i < 6 && v->minimap_parts[i] != NULL)
			mlx_destroy_image(v->mlx_ptr, v->minimap_parts[i]);
		if (i < 8 && v->minimap_player[i] != NULL)
			mlx_destroy_image(v->mlx_ptr, v->minimap_player[i]);
	}
}

void	error_exit(char *msg_1, char *msg_2, t_vars *v)
{
	if (msg_1 != NULL)
		ft_printf("%s\n", msg_1);
	if (msg_2 != NULL)
		ft_printf("%s\n", msg_2);
	free_v(v);
	exit(1);
}

void	normal_exit(char *msg_1, t_vars *v)
{
	if (msg_1 != NULL)
		ft_printf("%s\n", msg_1);
	free_v(v);
	exit(0);
}
