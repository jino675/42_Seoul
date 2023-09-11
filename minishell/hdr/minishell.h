/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 22:31:51 by jiryu            ###   ########.fr       */
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
	char			*args;
	char			**paths;
	char			**ev;
	t_cmd			*cmds;
	t_chunk			*chunk_list;
	char			*pwd;
	char			*o_pwd;
	int				pipes;
	int				*pid;
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
int				minishell(t_info *info);
int				reset_info(t_info *info);
void			free_strs(char **strs);
t_chunk			*chunk_new(char *str, int token);
void			chunk_list_push(t_chunk **list, t_chunk *new_chunk);
int				init_info_global(t_info *info);
char			**ft_strdup_arr(char **strs);
int				print_error(int code, t_info *info);
int				check_quotes(char *line);
int				read_token(t_info *info);
int				add_token(char *str, t_chunk **chunk_list);
t_token			check_token(char c);
int				make_new_chunk(char *str, t_token token, t_chunk **chunk_list);
void			chunk_list_erase(t_chunk **list, int key);
t_parse_info	init_parse_info(t_chunk *chunk_list, t_info *info);
t_cmd			*init_cmd(t_parse_info *parse_info);
void			chunk_list_clear(t_chunk **list);
int				print_token_error(t_info *info, t_chunk *chunk_list, \
															t_token token);
t_cmd			*cmd_new(char **strs, int num_redirs, t_chunk *redirs);
void			cmd_list_push(t_cmd **list, t_cmd *new_cmd);
void			chunk_clear_print_error(int code, t_info *info, \
														t_chunk *chunk_list);
int				make_cmds(t_info *info);

int				my_echo(t_info *info, t_cmd *cmd);
int				my_cd(t_info *info, t_cmd *cmd);
int				my_pwd(t_info *info, t_cmd *cmd);
int				my_export(t_info *info, t_cmd *cmd);
int				my_unset(t_info *info, t_cmd *cmd);
int				my_env(t_info *info, t_cmd *cmd);
int				my_exit(t_info *info, t_cmd *cmd);

#endif