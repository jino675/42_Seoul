/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_exec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:45:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/15 15:44:20 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	sub_free_path(t_etc *e)
{
	int	i;

	i = -1;
	while (e->paths[++i] != NULL)
		free(e->paths[i]);
	free(e->paths);
	e->paths = NULL;
}

static void	sub_find_path_default(t_etc *e, const char *cmd, char **res_adr)
{
	int		i;
	int		size;
	char	*tmp;

	size = 17 + ft_strlen(cmd) + 1;
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == NULL)
		error_exit(NULL, "memory allocation error!", e, 139);
	i = -1;
	while (++i < 6)
	{
		ft_strlcpy(tmp, e->default_paths[i], size);
		ft_strlcat(tmp, cmd, size);
		if (access(tmp, F_OK) == 0)
			e->cmd_flag = 1;
		if (access(tmp, X_OK) == 0)
		{
			*res_adr = tmp;
			return ;
		}
	}
	free(tmp);
}

static void	sub_find_path(t_etc *e, const char *cmd, char **res_adr)
{
	int		i;
	int		size;
	char	*tmp;

	i = -1;
	while (e->paths[++i] != NULL)
	{
		size = ft_strlen(e->paths[i]) + 1 + ft_strlen(cmd) + 1;
		tmp = (char *)malloc(sizeof(char) * size);
		if (tmp == NULL)
			error_exit(NULL, "memory allocation error!", e, 139);
		ft_strlcpy(tmp, e->paths[i], size);
		if (e->paths[i][ft_strlen(e->paths[i]) - 1] != '/')
			ft_strlcat(tmp, "/", size);
		ft_strlcat(tmp, cmd, size);
		if (access(tmp, F_OK) == 0)
			e->cmd_flag = 1;
		if (access(tmp, X_OK) == 0)
		{
			*res_adr = tmp;
			break ;
		}
		else
			free(tmp);
	}
}

static char	*find_path(t_etc *e, char **envp, const char *cmd)
{
	int		i;
	char	*str;
	char	*res;

	if (access(e->strs[0], X_OK) == 0 && ft_strchr(e->strs[0], '/') != NULL)
		return (e->strs[0]);
	res = NULL;
	i = -1;
	while (envp[++i] != NULL)
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			break ;
	if (envp[i] == NULL)
		sub_find_path_default(e, cmd, &res);
	else
	{
		str = &envp[i][5];
		e->paths = ft_split(str, ':');
		if (e->paths == NULL)
			error_exit(NULL, "memory allocation error!", e, 139);
		sub_find_path(e, cmd, &res);
		sub_free_path(e);
	}
	return (res);
}

void	pre_exec(t_etc *e, char *input, char **envp)
{
	if (access(input, F_OK) == 0)
	{
		if (access(input, X_OK) != 0)
			error_exit(input, "Permission denied", e, 127);
		e->strs = (char **)malloc(sizeof(char *) * 2);
		if (e->strs == NULL)
			error_exit(NULL, "memory allocation error!", e, 139);
		e->strs[0] = ft_strdup(input);
		if (e->strs[0] == NULL)
			error_exit(NULL, "memory allocation error!", e, 139);
		e->strs[1] = NULL;
	}
	else
	{
		e->strs = split_quote(input, ' ');
		if (e->strs == NULL)
			error_exit(NULL, "memory allocation error!", e, 139);
	}
	if (e->strs[0][ft_strlen(e->strs[0]) - 1] == '/')
		error_exit(NULL, "it is a directory", e, 127);
	e->cmd = find_path(e, envp, e->strs[0]);
	if (e->cmd == NULL && e->cmd_flag == 0)
		error_exit(e->strs[0], "command not found", e, 127);
	if (e->cmd == NULL && e->cmd_flag == 1)
		error_exit(e->strs[0], "Permission denied", e, 127);
}
