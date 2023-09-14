/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:29:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 22:37:23 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_path_ret(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (info->ev[i])
	{
		if (!ft_strncmp(info->ev[i], str, ft_strlen(str)))
			return (ft_substr(info->ev[i], ft_strlen(str),
					ft_strlen(info->ev[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

static int	specific_path(t_info *info, char *str)
{
	char	*tmp;
	int		ret;

	tmp = find_path_ret(str, info);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

static void	add_path_to_env(t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	while (info->ev[i])
	{
		if (!ft_strncmp(info->ev[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", info->pwd);
			free(info->ev[i]);
			info->ev[i] = tmp;
		}
		else if (!ft_strncmp(info->ev[i], "OLDPWD=", 7) && info->o_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", info->o_pwd);
			free(info->ev[i]);
			info->ev[i] = tmp;
		}
		i++;
	}
}

static void	change_path(t_info *info)
{
	char	*tmp;

	tmp = ft_strdup(info->pwd);
	free(info->o_pwd);
	info->o_pwd = tmp;
	free(info->pwd);
	info->pwd = getcwd(NULL, sizeof(NULL));
}

int	my_cd(t_info *info, t_cmd *cmd)
{
	int		ret;

	if (!cmd->strs[1])
		ret = specific_path(info, "HOME=");
	else if (ft_strncmp(cmd->strs[1], "-", 1) == 0)
		ret = specific_path(info, "OLDPWD=");
	else
	{
		ret = chdir(cmd->strs[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd->strs[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(info);
	add_path_to_env(info);
	return (EXIT_SUCCESS);
}