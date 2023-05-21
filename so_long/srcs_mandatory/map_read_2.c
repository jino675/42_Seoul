/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:42:18 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 21:45:01 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

static void	sub_check_component(t_vars *v, t_etc *e, int i, int j)
{
	if (i == 0 || i == v->map_height - 1 || j == 0 || j == v->map_width - 1)
		if (v->map[i][j] != '1')
			error_exit("Error", "outline must consist of '1'!", v, e);
	if (v->map[i][j] == 'P')
	{
		++v->p_count;
		v->p_x = j;
		v->p_y = i;
		v->map[i][j] = '0';
	}
	else if (v->map[i][j] == 'E')
	{
		++v->e_count;
		v->e_x = j;
		v->e_y = i;
	}
	else if (v->map[i][j] == 'C')
		++v->c_count;
	else if (v->map[i][j] != '0' && v->map[i][j] != '1')
		error_exit("Error", "there's weird component!", v, e);
}

void	check_component(t_vars *v, t_etc *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (v->map[i][++j] != '\0')
			sub_check_component(v, e, i, j);
	}
	if (v->p_count != 1)
		error_exit("Error", "player must be one!", v, e);
	if (v->e_count != 1)
		error_exit("Error", "exit must be one!", v, e);
	if (v->c_count <= 0)
		error_exit("Error", "collectible must be at least one!", v, e);
}
