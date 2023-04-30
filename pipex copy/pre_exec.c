/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:45:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/28 15:38:49 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sub_free(t_etc *e)
{
	int	i;

	i = -1;
	while (e->paths[++i] != NULL)
		free(e->paths[i]);
	free(e->paths);
}

static void	sub_find(t_etc *e, const char *cmd, char **res_adr)
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
			error_exit("memory allocation error!\n", e);
		ft_strlcpy(tmp, e->paths[i], size);
		ft_strlcat(tmp, "/", size);
		ft_strlcat(tmp, cmd, size);
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

	res = NULL;
	i = -1;
	while (envp[++i] != NULL)
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			break ;
	if (envp[i] == NULL)
		return (NULL);
	str = &envp[i][5];
	e->paths = ft_split(str, ':');
	if (e->paths == NULL)
		error_exit("memory allocation error!\n", e);
	sub_find(e, cmd, &res);
	sub_free(e);
	return (res);
}

void	pre_exec(t_etc *e, char *input, char **envp)
{
	e->strs = split_quote(input, ' ');
	if (e->strs == NULL)
		error_exit("memory allocation error!\n", e);
	if (ft_strncmp(e->strs[0], "awk", 3) == 0)
		split_awk(e);
	int	i;
	i = -1;
	while (e->strs[++i] != NULL)
		ft_printf("%s\n", e->strs[i]);
	e->cmd = find_path(e, envp, e->strs[0]);
	if (e->cmd == NULL)
		error_exit("command not found\n", e);
}