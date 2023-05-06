/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:55:28 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/06 18:13:58 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_etc
{
	int		*pids;
	int		idx_pids;
	int		**fds;
	int		idx_fds;
	int		fd_in;
	int		fd_out;
	int		is_hd;
	int		idx_file;
	int		idx_cmd;
	int		cmd_count;
	char	**strs;
	char	**paths;
	char	*cmd;
	char	default_paths[6][18];
}	t_etc;

typedef struct s_etc_2
{
	int		x_idx;
	int		y_idx;
	int		flag;
	int		each_size;
	int		word_count;
	char	**res;
}	t_etc_2;

void	error_exit(char const *msg_1, char const *msg_2, t_etc *e);
void	pre_exec(t_etc *e, char *input, char **envp);
void	pipe_run(t_etc *e, int argc, char **argv, char **envp);
char	**split_quote(char const *s, char c);
void	split_awk(t_etc *e);
int		here_doc(t_etc *e, char *limiter);

#endif