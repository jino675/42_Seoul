/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:09:57 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/13 20:22:29 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**strdup_arr(char **strs)
{
	int		i;
	char	**res;
	size_t	cnt;

	cnt = 0;
	while (strs[cnt] != NULL)
		cnt++;
	res = ft_calloc(sizeof(char *), cnt + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < (int)cnt)
	{
		res[i] = ft_strdup(strs[i]);
		if (res[i] == NULL)
		{
			free_strs(res);
			return (res);
		}
	}
	return (res);
}

int	print_error(int code, t_info *info)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (code == 0)
		ft_putstr_fd("syntax error near unexpected token 'newline'\n",	\
			STDERR_FILENO);
	else if (code == 1)
		ft_putstr_fd("memory error: unable to assign memory\n", STDERR_FILENO);
	else if (code == 2)
		ft_putstr_fd("syntax error: unable to locate closing quotation\n",
			STDERR_FILENO);
	else if (code == 3)
		ft_putstr_fd("Parser problem\n", STDERR_FILENO);
	else if (code == 4)
		ft_putstr_fd("Failed to create pipe\n", STDERR_FILENO);
	else if (code == 5)
		ft_putstr_fd("Failed to fork\n", STDERR_FILENO);
	else if (code == 6)
		ft_putstr_fd("outfile: Error\n", STDERR_FILENO);
	else if (code == 7)
		ft_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
	else if (code == 8)
		ft_putendl_fd("Path does not exist", STDERR_FILENO);
	restart_minishell(info);
	return (EXIT_FAILURE);
}