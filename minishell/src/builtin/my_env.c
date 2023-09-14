/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:29:40 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 22:27:41 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_env(t_info *info, t_cmd *cmd)
{
	int		i;

	(void) cmd;
	i = 0;
	while (info->ev[i])
	{
		ft_putendl_fd(info->ev[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}