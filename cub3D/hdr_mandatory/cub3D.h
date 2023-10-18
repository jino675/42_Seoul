/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:01:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/18 00:36:45 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include "libft.h"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WALL_DEFAULT_SIZE 1000
# define STAFF_SIZE 500
# define MOVING_UNIT 0.05
# define MOVING_THRES 0.1
# define STAFF_THRES 0.3

typedef enum e_key
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	left = 123,
	right = 124,
	Space = 49,
	Esc = 53
}	t_key;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				map_width;
	int				map_height;
	void			*view;
	void			*wall[5];
	char			*wall_path[5];
	char			*wall_addr[5];
	int				wall_bpp;
	int				wall_line_len;
	int				wall_endian;
	char			*view_addr;
	int				view_bpp;
	int				view_line_len;
	int				view_endian;
	void			*minimap_parts[6];
	void			*minimap;
	char			*minimap_addr;
	int				minimap_bpp;
	int				minimap_line_len;
	int				minimap_endian;
	int				f_rgb;
	int				c_rgb;
	void			*staff[5];
	int				is_moving;
	int				is_changing;
	char			*map_path;
	char			*img_path;
	int				new_draw;
	double			p_x;
	double			p_y;
	int				int_x;
	int				int_y;
	double			p_d;
	int				p_s;
	int				is_end;
	struct timespec	pre_time;
}	t_vars;

typedef struct s_etc
{
	int		fd;
	int		cur_length;
	char	*cur_line;
	int		d_cnt;
	char	**parts;
	int		color;
	int		is_map;
	int		size;
	int		top;
	char	**map;
	int		max_len;
}	t_etc;

typedef struct s_cal
{
	int				cur_x;
	int				cur_y;
	double			cur_d;
	double			add_x;
	double			add_y;
	double			distance;
	int				wall_idx;
	int				wall_line_idx;
	unsigned int	*wall_line;
	double			ratio;
}	t_cal;

void	error_exit(char *msg_1, char *msg_2, t_vars *v);
void	normal_exit(char *msg_1, t_vars *v);
void	map_read(t_vars *v, int ac, char **av);
void	load_images(t_vars *v);
void	init_vars(t_vars *v);
void	init_mlx_win(t_vars *v);
int		key_down_hook(int key, t_vars *v);
int		mouse_move_hook(int x, int y, t_vars *v);
int		mouse_click_hook(int button, int x, int y, t_vars *v);
int		key_up_hook(int key, t_vars *v);
int		exit_hook(t_vars *v);
int		loop_hook(t_vars *v);
void	draw_view(t_vars *v);
void	draw_minimap(t_vars *v);

#endif