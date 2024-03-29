/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:12:14 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/15 15:45:17 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	double_free_int(int **arrs)
{
	int	i;

	i = -1;
	while (arrs[++i] != NULL)
		free(arrs[i]);
	free(arrs);
}

static void	double_free_char(char **arrs)
{
	int	i;

	i = -1;
	while (arrs[++i] != NULL)
		free(arrs[i]);
	free(arrs);
}

void	error_exit(char const *msg_1, char const *msg_2, t_etc *e, int code)
{
	write(2, "pipex: ", 7);
	if (msg_1 != NULL)
	{
		write(2, msg_1, ft_strlen(msg_1));
		write(2, ": ", 2);
	}
	if (msg_2 != NULL)
		write(2, msg_2, ft_strlen(msg_2));
	write(2, "\n", 1);
	if (e != NULL)
	{
		if (e->pids != NULL)
			free(e->pids);
		if (e->fds != NULL)
			double_free_int(e->fds);
		if (e->strs != NULL)
			double_free_char(e->strs);
		if (e->paths != NULL)
			double_free_char(e->paths);
		if (e->cmd != NULL)
			free(e->cmd);
		if (e->temp_file != NULL)
			free(e->temp_file);
	}
	exit(code);
}

void	normal_exit(t_etc *e, int code)
{
	if (e != NULL)
	{
		if (e->pids != NULL)
			free(e->pids);
		if (e->fds != NULL)
			double_free_int(e->fds);
		if (e->strs != NULL)
			double_free_char(e->strs);
		if (e->paths != NULL)
			double_free_char(e->paths);
		if (e->cmd != NULL)
			free(e->cmd);
		if (e->temp_file != NULL)
			free(e->temp_file);
	}
	exit(code);
}
