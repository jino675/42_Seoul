/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:53:07 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/22 20:25:52 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_new(char **strs, int num_redirs, t_chunk *redirs);

static void	add_redirection(t_parse_info *parse_info, t_chunk *cur_chunk, \
														t_chunk *next_chunk)
{
	t_chunk	*new_chunk;

	new_chunk = chunk_new(ft_strdup(next_chunk->str), cur_chunk->token);
	if (new_chunk == NULL)
		chunk_clear_print_error(1, parse_info->info, parse_info->chunk_list);
	chunk_list_push(&parse_info->redirs, new_chunk);
	chunk_list_erase(&parse_info->chunk_list, cur_chunk->idx);
	chunk_list_erase(&parse_info->chunk_list, next_chunk->idx);
	++parse_info->num_redirs;
}

static void	collect_redirection(t_parse_info *parse_info)
{
	t_chunk	*cur_chunk;

	while (true)
	{
		cur_chunk = parse_info->chunk_list;
		while (cur_chunk != NULL && cur_chunk->token == 0)
			cur_chunk = cur_chunk->next;
		if (cur_chunk == NULL || cur_chunk->token == PIPE)
			return ;
		if (cur_chunk->next == NULL)
			chunk_clear_print_error(0, parse_info->info, \
										parse_info->chunk_list);
		if (cur_chunk->next->token != 0)
			print_token_error(parse_info->info,
				parse_info->chunk_list, cur_chunk->next->token);
		if ((cur_chunk->token >= OUT && cur_chunk->token <= D_IN))
			add_redirection(parse_info, cur_chunk, cur_chunk->next);
	}
}

static int	count_cur_args(t_chunk *chunk_list)
{
	int		arg_cnt;
	t_chunk	*cur_chunk;

	arg_cnt = 0;
	cur_chunk = chunk_list;
	while (cur_chunk != NULL && cur_chunk->token != PIPE)
	{
		++arg_cnt;
		cur_chunk = cur_chunk->next;
	}
	return (arg_cnt);
}

t_cmd	*init_cmd(t_parse_info *parse_info)
{
	int		i;
	int		cur_arg_cnt;
	char	**strs;
	t_chunk	*cur_chunk;

	collect_redirection(parse_info);
	cur_arg_cnt = count_cur_args(parse_info->chunk_list);
	strs = ft_calloc(cur_arg_cnt + 1, sizeof(char *));
	// if (strs == NULL)
		// chunk_clear_print_error(1, parse_info->info, parse_info->chunk_list);
	i = -1;
	cur_chunk = parse_info->chunk_list;
	while (--cur_arg_cnt >= 0)
	{
		if (cur_chunk->str != NULL)
		{
			strs[++i] = ft_strdup(cur_chunk->str);
			chunk_list_erase(&parse_info->chunk_list, cur_chunk->idx);
			cur_chunk = parse_info->chunk_list;
		}
	}
	return (cmd_new(strs, parse_info->num_redirs, parse_info->redirs));
}

int	print_token_error(t_info *info, t_chunk *chunk_list, t_token token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", \
													STDERR_FILENO);
	if (token == OUT)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == D_OUT)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == IN)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == D_IN)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	chunk_list_clear(&chunk_list);
	return (restart_minishell(info));
}
