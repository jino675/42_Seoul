/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:23 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 21:21:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

static void	sub_free_v(t_vars *v)
{
	if (v->file_name != NULL)
		free(v->file_name);
	if (v->rock_img != NULL)
		mlx_destroy_image(v->mlx_ptr, v->rock_img);
	if (v->grass_img != NULL)
		mlx_destroy_image(v->mlx_ptr, v->grass_img);
	if (v->heart_img != NULL)
		mlx_destroy_image(v->mlx_ptr, v->heart_img);
	if (v->sign_img != NULL)
		mlx_destroy_image(v->mlx_ptr, v->sign_img);
	if (v->img_path != NULL)
		free(v->img_path);
	if (v->win_ptr != NULL)
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
}

static void	free_v(t_vars *v)
{
	int	i;
	int	j;

	sub_free_v(v);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (v->player_img_walk[i][j] != NULL)
				mlx_destroy_image(v->mlx_ptr, v->player_img_walk[i][j]);
			if (v->player_img_idle[i][j] != NULL)
				mlx_destroy_image(v->mlx_ptr, v->player_img_idle[i][j]);
			if (v->enemy_img_sword[i][j] != NULL)
				mlx_destroy_image(v->mlx_ptr, v->enemy_img_sword[i][j]);
			if (v->enemy_img_idle[i][j] != NULL)
				mlx_destroy_image(v->mlx_ptr, v->enemy_img_idle[i][j]);
		}
	}
	i = -1;
	while (v->map[++i] != NULL)
		free(v->map[i]);
}

void	error_exit(char *msg_1, char *msg_2, t_vars *v, t_etc *e)
{
	int	i;

	if (msg_1 != NULL)
		ft_printf("%s\n", msg_1);
	if (msg_2 != NULL)
		ft_printf("%s\n", msg_2);
	if (v != NULL)
		free_v(v);
	if (e != NULL)
	{
		i = -1;
		while (e->temp_map[++i] != NULL)
			free(e->temp_map[i]);
	}
	exit(1);
}

void	normal_exit(t_vars *v)
{
	if (v != NULL)
		free_v(v);
	exit(0);
}
