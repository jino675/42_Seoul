/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:51:32 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/15 15:43:59 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	init_zero_e(t_etc *e)
{
	e->pids = NULL;
	e->fds = NULL;
	e->idx_pids = 0;
	e->idx_fds = 0;
	e->fd_in = 0;
	e->fd_out = 0;
	e->is_hd = 0;
	e->idx_file = 0;
	e->idx_cmd = 0;
	e->cmd_count = 0;
	e->cmd_flag = 0;
	e->strs = NULL;
	e->paths = NULL;
	e->cmd = NULL;
	e->temp_file = NULL;
	ft_strlcpy(e->default_paths[0], "/bin/", 18);
	ft_strlcpy(e->default_paths[1], "/sbin/", 18);
	ft_strlcpy(e->default_paths[2], "/usr/bin/", 18);
	ft_strlcpy(e->default_paths[3], "/usr/sbin/", 18);
	ft_strlcpy(e->default_paths[4], "/usr/local/bin/", 18);
	ft_strlcpy(e->default_paths[5], "/usr/local/munki/", 18);
}

int	main(int argc, char **av, char **envp)
{
	t_etc	e;

	init_zero_e(&e);
	pipe_run(&e, argc, av, envp);
	return (0);
}
