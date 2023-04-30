/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:55:28 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/28 15:51:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_etc
{
	int		*pids;
	int		**fds;
	int		fd_in;
	int		fd_out;
	char	**strs;
	char	**paths;
	char	*cmd;
}	t_etc;

typedef struct s_etc_2
{
	int		x_idx;
	int		y_idx;
	int		flag;
	int		size;
	int		count;
	char	**res;
}	t_etc_2;

void	error_exit(char const *msg, t_etc *e);
void	pre_exec(t_etc *e, char *input, char **envp);
void	pipe_run(t_etc *e, int argc, char **argv, char **envp);
char	**split_quote(char const *s, char c);
void	split_awk(t_etc *e);

#endif