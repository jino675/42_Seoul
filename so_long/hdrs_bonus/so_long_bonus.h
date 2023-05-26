/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:01:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/24 15:13:48 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"
# define MAP_UNIT 32
# define MAP_HEIGHT_MAX 30
# define MAP_WIDTH_MAX 30

typedef enum e_key
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	Esc = 53
}	t_key;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*file_name;
	char			*map[MAP_HEIGHT_MAX + 1];
	int				map_width;
	int				map_height;
	void			*rock_img;
	void			*grass_img;
	void			*heart_img;
	void			*sign_img;
	void			*player_img_walk[4][4];
	void			*player_img_idle[4][4];
	void			*enemy_img_sword[4][4];
	void			*enemy_img_idle[4][4];
	char			*img_path;
	char			*move_str;
	unsigned int	move_count;
	int				is_moving_p;
	int				is_moving_e;
	int				p_x;
	int				p_y;
	int				p_d;
	int				p_s;
	int				e_x;
	int				e_y;
	int				e_d;
	int				e_s;
	unsigned long	r_seed;
	int				p_count;
	int				e_count;
	int				c_count;
}	t_vars;

typedef struct s_etc
{
	int		fd;
	int		cur_length;
	char	*cur_line;
	int		cur_e_count;
	int		cur_c_count;
	char	*temp_map[MAP_HEIGHT_MAX + 1];
}	t_etc;

void	error_exit(char *msg_1, char *msg_2, t_vars *v, t_etc *e);
void	normal_exit(t_vars *v);
void	map_read(t_vars *v, int ac, char **av);
void	load_images(t_vars *v);
void	init_vars(t_vars *v);
void	init_mlx_win(t_vars *v);
int		key_down_hook(int key, t_vars *v);
int		key_up_hook(int key, t_vars *v);
int		exit_hook(t_vars *v);
int		loop_hook(t_vars *v);

#endif