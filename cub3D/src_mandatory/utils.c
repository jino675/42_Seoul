/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:23 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/18 00:29:29 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_v(t_vars *v)
{
	int	i;

	if (v->win_ptr != NULL)
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	i = -1;
	while (++i < 5)
	{
		if (i < 4 && v->wall[i] != NULL)
			mlx_destroy_image(v->mlx_ptr, v->wall[i]);
		if (v->staff[i] != NULL)
			mlx_destroy_image(v->mlx_ptr, v->staff[i]);
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
