/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:24:50 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/08 22:39:33 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

typedef struct s_etc
{
	int		is_p;
	int		is_e;
	int		is_c;
	int		fd;
	int		cur_length;
	char	*cur_line;
}	t_etc;

void	map_check_clear(t_var *v)
{
	int		i;
	char	**temp_map;

	temp_map = (char **)malloc(sizeof(char *) * v->map_height);
	if (temp_map == NULL)
		error_exit(NULL, "memory allocation error!", v);
	i = -1;
	while (++i < v->map_height)
	{
		temp_map[i] = (char *)malloc(sizeof(char) * v->map_width + 1);
		if (temp_map[i] == NULL)
			error_exit(NULL, "memory allocation error!", v);
		ft_strlcpy(temp_map[i], v->map[i], v->width + 1);
	}
	bfs(temp_map, v->p_x, v->p_y)
}