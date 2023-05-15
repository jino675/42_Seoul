/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:01:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/08 22:38:59 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# define MAP_HEIGHT_MAX 50

typedef enum e_button
{
	Left = 1,
	Right = 2,
	Middle = 3,
	Up = 4,
	Down = 5
}	t_button;

typedef enum e_key
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	Esc = 53,
	Space = 49
}	t_key;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		is_button;
	int		cur_button;
	char	*map[MAP_HEIGHT_MAX + 1];
	int		map_width;
	int		map_height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
}	t_vars;

void	error_exit(char *msg_1, char *msg_2, t_vars *v);

#endif