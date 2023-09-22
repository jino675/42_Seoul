/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:29:42 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/22 20:25:11 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmds_clear(t_cmd **cmd_list_addr);

static void	free_info(t_info *info)
{
	free(info->line);
	free_strs(info->paths);
	free_strs(info->ev);
	free_strs(info->not_ev);
	cmds_clear(&info->cmds);
	free(info->pwd);
	free(info->o_pwd);
	if (info->pipes != 0)
		free(info->pids);
}

static int	is_nbr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]) == 0)
			return (0);
	return (1);
}

static void	run_exit(char **strs)
{
	int	exit_code;

	if (strs[1] == NULL)
		exit_code = 0;
	else if (is_nbr(strs[1]) == 1)
		exit_code = ft_atoi(strs[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(strs[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_strs(strs);
	exit(exit_code);
}

int	my_exit(t_info *info, t_cmd *cmd)
{
	char	**strs;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (cmd->strs[1] != NULL && cmd->strs[2] != NULL)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	strs = strdup_arr(cmd->strs);
	free_info(info);
	run_exit(strs);
	return (EXIT_SUCCESS);
}
