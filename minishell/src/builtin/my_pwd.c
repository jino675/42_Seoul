/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:29:44 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 22:31:57 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_pwd(t_info *info, t_cmd *cmd)
{
	(void) cmd;
	ft_putendl_fd(info->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}