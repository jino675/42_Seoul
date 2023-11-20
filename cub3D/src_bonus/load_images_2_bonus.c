/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:08:20 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/23 16:20:30 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sub_load_minimap_3(t_vars *v)
{
	int	width;
	int	height;
	int	buf;

	v->minimap_player[6] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_N.xpm", &width, &height);
	if (v->minimap_player[6] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_player[7] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_NE.xpm", &width, &height);
	if (v->minimap_player[7] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/minimap.xpm", &width, &height);
	if (v->minimap == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_addr = mlx_get_data_addr(v->minimap, &buf, &buf, &buf);
	if (v->minimap_addr == NULL)
		error_exit("Error", "memory allocation error", v);
}

static void	sub_load_minimap_2(t_vars *v)
{
	int	width;
	int	height;

	v->minimap_player[2] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_S.xpm", &width, &height);
	if (v->minimap_player[2] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_player[3] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_SW.xpm", &width, &height);
	if (v->minimap_player[3] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_player[4] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_W.xpm", &width, &height);
	if (v->minimap_player[4] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_player[5] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_NW.xpm", &width, &height);
	if (v->minimap_player[5] == NULL)
		error_exit("Error", "memory allocation error", v);
	sub_load_minimap_3(v);
}

static void	sub_load_minimap_1(t_vars *v)
{
	int	width;
	int	height;

	v->minimap_parts[4] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/goal.xpm", &width, &height);
	if (v->minimap_parts[4] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_parts[5] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/ground.xpm", &width, &height);
	if (v->minimap_parts[4] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_player[0] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_E.xpm", &width, &height);
	if (v->minimap_player[0] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_player[1] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/player_SE.xpm", &width, &height);
	if (v->minimap_player[1] == NULL)
		error_exit("Error", "memory allocation error", v);
	sub_load_minimap_2(v);
}

void	load_minimap(t_vars *v)
{
	int	width;
	int	height;

	v->minimap_parts[0] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/door_closed.xpm", &width, &height);
	if (v->minimap_parts[0] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_parts[1] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/door_opened.xpm", &width, &height);
	if (v->minimap_parts[1] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_parts[2] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/null.xpm", &width, &height);
	if (v->minimap_parts[2] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->minimap_parts[3] = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/minimap/wall.xpm", &width, &height);
	if (v->minimap_parts[3] == NULL)
		error_exit("Error", "memory allocation error", v);
	sub_load_minimap_1(v);
}
