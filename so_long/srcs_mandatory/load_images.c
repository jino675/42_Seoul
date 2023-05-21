/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:44 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 18:27:52 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

static void	sub_load_images_etcs(t_vars *v)
{
	int	width;
	int	height;

	v->grass_img = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/Grass.xpm", &width, &height);
	v->rock_img = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/Rock.xpm", &width, &height);
	v->heart_img = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/Heart.xpm", &width, &height);
	v->sign_img = mlx_xpm_file_to_image(v->mlx_ptr, \
		"./asset/images/Sign.xpm", &width, &height);
}

static void	sub_load_images_player(t_vars *v, char *tmp, int i, int j)
{
	int	width;
	int	height;

	ft_strlcpy(v->img_path, "./asset/images/Player_walk/img", 50);
	ft_strattach(&v->img_path, tmp);
	ft_strattach(&v->img_path, ".xpm");
	v->player_img_walk[i][j] = mlx_xpm_file_to_image(v->mlx_ptr, \
		v->img_path, &width, &height);
	if (v->player_img_walk[i][j] == NULL)
		error_exit("Error", "memory allocation error", v, NULL);
	ft_strlcpy(v->img_path, "./asset/images/Player_idle/img", 50);
	ft_strattach(&v->img_path, tmp);
	ft_strattach(&v->img_path, ".xpm");
	v->player_img_idle[i][j] = mlx_xpm_file_to_image(v->mlx_ptr, \
		v->img_path, &width, &height);
	if (v->player_img_idle[i][j] == NULL)
		error_exit("Error", "memory allocation error", v, NULL);
}

static void	sub_load_images_enemy(t_vars *v, char *tmp, int i, int j)
{
	int	width;
	int	height;

	ft_strlcpy(v->img_path, "./asset/images/Enemy_sword/img", 50);
	ft_strattach(&v->img_path, tmp);
	ft_strattach(&v->img_path, ".xpm");
	v->enemy_img_sword[i][j] = mlx_xpm_file_to_image(v->mlx_ptr, \
		v->img_path, &width, &height);
	if (v->enemy_img_sword[i][j] == NULL)
		error_exit("Error", "memory allocation error", v, NULL);
	ft_strlcpy(v->img_path, "./asset/images/Enemy_idle/img", 50);
	ft_strattach(&v->img_path, tmp);
	ft_strattach(&v->img_path, ".xpm");
	v->enemy_img_idle[i][j] = mlx_xpm_file_to_image(v->mlx_ptr, \
		v->img_path, &width, &height);
	if (v->enemy_img_idle[i][j] == NULL)
		error_exit("Error", "memory allocation error", v, NULL);
}

void	load_images(t_vars *v)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	sub_load_images_etcs(v);
	v->img_path = (char *)malloc(sizeof(char) * 50);
	if (v->img_path == NULL)
		error_exit("Error", "memory allocation error", v, NULL);
	k = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tmp = ft_itoa(++k);
			if (tmp == NULL)
				error_exit("Error", "memory allocation error", v, NULL);
			sub_load_images_player(v, tmp, i, j);
			sub_load_images_enemy(v, tmp, i, j);
			free(tmp);
		}
	}
}
