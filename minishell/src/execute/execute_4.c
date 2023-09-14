/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:56:09 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 16:06:38 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}

static char	**resplit_str(char **double_arr)
{
	char	**ret;
	char	*joined_str;

	joined_str = join_split_str(double_arr, NULL);
	free_strs(double_arr);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = join_split_str(ret, NULL);
	free_strs(ret);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	return (ret);
}

static int	cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

int	find_cmd(t_cmd *cmd, t_info *info)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->strs = resplit_str(cmd->strs);
	if (!access(cmd->strs[0], F_OK))
		execve(cmd->strs[0], cmd->strs, info->ev);
	while (info->paths[i])
	{
		mycmd = ft_strjoin(info->paths[i], cmd->strs[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->strs, info->ev);
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->strs[0]));
}

t_cmd	*get_first_cmd(t_cmd *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		i++;
	}
	return (map);
}