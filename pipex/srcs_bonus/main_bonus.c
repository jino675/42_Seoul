/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:51:32 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/03 21:21:35 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

// static void	init_e(t_etc *e)
// {
// 	e->pids = NULL;
// 	e->fds = NULL;
// 	e->idx_pids = 0;
// 	e->idx_fds = 0;
// 	e->fd_in = 0;
// 	e->fd_out = 0;
// 	e->is_hd = 0;
// 	e->idx_file = 0;
// 	e->idx_cmd = 0;
// 	e->cmd_count = 0;
// 	e->strs = NULL;
// 	e->paths = NULL;
// 	e->cmd = NULL;
// }

int	main(int argc, char **argv, char **envp)
{
	static t_etc	e;

	// init_e(&e);
	pipe_run(&e, argc, argv, envp);
	return (0);
}
