/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:12:14 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/28 16:04:07 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	double_free_1(int **arrs)
{
	int	i;

	i = -1;
	while (arrs[++i] != NULL)
		free(arrs[i]);
	free(arrs);
}

static void	double_free_2(char **arrs)
{
	int	i;

	i = -1;
	while (arrs[++i] != NULL)
		free(arrs[i]);
	free(arrs);
}

void	error_exit(char const *msg, t_etc *e)
{
	if (e != NULL)
	{
		if (e->pids != NULL)
			free(e->pids);
		if (e->fds != NULL)
			double_free_1(e->fds);
		if (e->strs != NULL)
			double_free_2(e->strs);
		if (e->paths != NULL)
			double_free_2(e->paths);
		if (e->cmd != NULL)
			free(e->cmd);
	}
	perror(msg);
	exit(1);
}
