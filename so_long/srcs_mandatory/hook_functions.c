/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:55:19 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/21 21:18:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/so_long.h"

void	move_player(t_vars *t, int key);

int	key_down_hook(int key, t_vars *v)
{
	move_player(v, key);
	return (0);
}

int	key_up_hook(int key, t_vars *v)
{
	if (key == Esc)
		normal_exit(v);
	return (0);
}

int	exit_hook(t_vars *v)
{
	normal_exit(v);
	return (0);
}
