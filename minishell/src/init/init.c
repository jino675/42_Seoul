/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:12:31 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 15:54:05 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_pwd(t_info *info)
{
	int	i;

	i = -1;
	while (info->ev[++i] != NULL)
	{
		if (ft_strncmp(info->ev[i], "PWD=", 4) == 0)
			info->pwd = ft_substr(info->ev[i], 4, ft_strlen(info->ev[i]) - 4);
		if (ft_strncmp(info->ev[i], "OLDPWD=", 7) == 0)
			info->o_pwd = ft_substr(info->ev[i], 7, ft_strlen(info->ev[i]) - 7);
	}
	return (1);
}

static char	*sub_find_paths(char **ev)
{
	int		i;

	i = -1;
	while (ev[++i] != NULL)
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
			return (ft_substr(ev[i], 5, ft_strlen(ev[i]) - 5));
	return (ft_strdup("\0"));
}

static int	find_paths(t_info *info)
{
	char	*paths;
	int		i;
	size_t	cur_len;

	paths = sub_find_paths(info->ev);
	info->paths = ft_split(paths, ':');
	free(paths);
	i = -1;
	while (info->paths[++i])
	{
		cur_len = ft_strlen(info->paths[i]);
		if (ft_strncmp(&info->paths[i][cur_len - 1], "/", 1) != 0)
			ft_strattach(&info->paths[i], "/");
	}
	return (EXIT_SUCCESS);
}

int	init_info_global(t_info *info)
{
	info->cmds = NULL;
	info->chunk_list = NULL;
	info->reset = false;
	info->pids = NULL;
	info->heredoc = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	find_paths(info);
	init_signals();
	return (1);
}

void	initialize(t_info *info, char **ev)
{
	info->ev = strdup_arr(ev);
	check_pwd(info);
	init_info_global(info);
	printf("\nWellcome to Minishell!\n\n");
}
