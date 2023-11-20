/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:44 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/21 18:28:34 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_minimap(t_vars *v);

static void	load_images_wall(t_vars *v, int i)
{
	int	width;
	int	height;
	int	buf;

	v->wall[i] = mlx_xpm_file_to_image(v->mlx_ptr, \
								v->wall_path[i], &width, &height);
	if (v->wall[i] == NULL)
		error_exit("Error", "memory allocation error", v);
	v->wall_addr[i] = mlx_get_data_addr(v->wall[i], &buf, &buf, &buf);
	if (v->wall_addr[i] == NULL)
		error_exit("Error", "memory allocation error", v);
}

static void	load_images_staff(t_vars *v, char *tmp, int i)
{
	int	width;
	int	height;

	ft_strlcpy(v->img_path, "./asset/images/staff/img_", 50);
	if (ft_strattach(&v->img_path, tmp) == -1)
		error_exit("Error", "memory allocation error", v);
	if (ft_strattach(&v->img_path, ".xpm") == -1)
		error_exit("Error", "memory allocation error", v);
	v->staff[i] = mlx_xpm_file_to_image(v->mlx_ptr, \
		v->img_path, &width, &height);
	if (v->staff[i] == NULL)
		error_exit("Error", "memory allocation error", v);
}

static void	load_view(t_vars *v)
{
	int	width;
	int	height;
	int	buf;

	v->view = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/view.xpm", &width, &height);
	if (v->view == NULL)
		error_exit("Error", "memory allocation error", v);
	v->view_addr = mlx_get_data_addr(v->view, &buf, &buf, &buf);
	if (v->view_addr == NULL)
		error_exit("Error", "memory allocation error", v);
}

void	load_images(t_vars *v)
{
	int		i;
	char	*tmp;

	v->img_path = (char *)ft_calloc(50, sizeof(char));
	if (v->img_path == NULL)
		error_exit("Error", "memory allocation error", v);
	i = -1;
	while (++i < 5)
	{
		tmp = ft_itoa(i);
		if (tmp == NULL)
			error_exit("Error", "memory allocation error", v);
		load_images_wall(v, i);
		load_images_staff(v, tmp, i);
		free(tmp);
	}
	load_view(v);
	load_minimap(v);
	free(v->img_path);
}
