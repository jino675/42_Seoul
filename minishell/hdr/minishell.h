/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 22:06:08 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

struct					s_cmd;
typedef struct s_cmd	t_cmd;

typedef enum s_token
{
	PIPE = 1,
	OUT,
	D_OUT,
	IN,
	D_IN,
}	t_token;

typedef struct s_chunk
{
	char			*str;
	t_token			token;
	int				idx;
	struct s_chunk	*next;
	struct s_chunk	*prev;
}	t_chunk;

typedef struct s_info
{
	char			*line;
	char			**paths;
	char			**ev;
	t_cmd			*cmds;
	t_chunk			*chunk_list;
	char			*pwd;
	char			*o_pwd;
	int				pipes;
	int				*pids;
	bool			heredoc;
	bool			reset;
}	t_info;

typedef struct s_cmd
{
	char			**strs;
	int				(*builtin)(t_info *, struct s_cmd *);
	int				num_redirs;
	char			*hd_file_name;
	t_chunk			*redirs;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_parse_info
{
	t_chunk			*chunk_list;
	t_chunk			*redirs;
	int				num_redirs;
	struct s_info	*info;
}	t_parse_info;

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

t_global				g_global;

void			initialize(t_info *info, char **ev);
int				init_info_global(t_info *info);

int				minishell(t_info *info);
int				restart_minishell(t_info *info);

void			free_strs(char **strs);
char			**strdup_arr(char **strs);
int				print_error(int code, t_info *info);

int				check_quotes(char *line);
int				make_chunks(t_info *info);
int				add_token(char *str, t_chunk **chunk_list_addr);
t_token			what_token(char c);
int				make_new_chunk(char *str, t_token token, \
													t_chunk **chunk_list_addr);
void			chunk_list_push(t_chunk **chunk_list_addr, t_chunk *new_chunk);
t_chunk			*chunk_new(char *str, int token);

int				make_cmds(t_info *info);
void			chunk_list_clear(t_chunk **chunk_list_addr);
void			chunk_list_erase(t_chunk **chunk_list_addr, int key);
int				print_token_error(t_info *info, t_chunk *chunk_list, \
															t_token token);
t_cmd			*init_cmd(t_parse_info *parse_info);
t_cmd			*cmd_new(char **strs, int num_redirs, t_chunk *redirs);
void			cmd_list_push(t_cmd **cmd_list_addr, t_cmd *new_cmd);
void			chunk_clear_print_error(int code, t_info *info, \
														t_chunk *chunk_list);

void			dollar_all(t_info *info, char **str_addr);
char			*delete_quotes(char *str, char c);
char			**expander(t_info *info, char **strs);
char			*expander_str(t_info *info, char *str);
int				dollar_general(t_info *info, char **str_addr, int cur_idx);

void			single_cmd(t_cmd *cmd, t_info *info);
int				execute(t_info *info);
int				check_fd_heredoc(t_info *info, int end[2], t_cmd *cmd);
int				send_heredoc(t_info *info, t_cmd *cmd);
int				check_redirections(t_cmd *cmd);
void			handle_cmd(t_cmd *cmd, t_info *info);
int				find_cmd(t_cmd *cmd, t_info *info);
t_cmd			*get_first_cmd(t_cmd *map);
int				ft_fork(t_info *info, int end[2], int fd_in, t_cmd *cmd);
int				pipe_wait(int *pid, int amount);


void			init_signals(void);
void			sig_quit(int signal);

int				my_echo(t_info *info, t_cmd *cmd);
int				my_cd(t_info *info, t_cmd *cmd);
int				my_pwd(t_info *info, t_cmd *cmd);
int				my_export(t_info *info, t_cmd *cmd);
int				my_unset(t_info *info, t_cmd *cmd);
int				my_env(t_info *info, t_cmd *cmd);
int				my_exit(t_info *info, t_cmd *cmd);

#endif