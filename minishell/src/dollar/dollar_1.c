/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:11:40 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/22 17:49:12 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_all(t_info *info, char **str_addr);
void	delete_quotes(char *str);

static int	find_dollar_next_idx(char *str)
{
	int	s_cnt;
	int	i;

	i = -1;
	s_cnt = 0;
	while (str[++i] != '\0')
	{
		if (s_cnt % 2 == 0 && str[i] == '$')
			return (i + 1);
		if (str[i] == '\'')
			++s_cnt;
	}
	return (0);
}

static void	dollar_strs(t_info *info, char **strs)
{
	int		i;
	int		dollar_next_idx;

	i = -1;
	while (strs[++i] != NULL)
	{
		dollar_next_idx = find_dollar_next_idx(strs[i]);
		if (dollar_next_idx != 0 && strs[i][dollar_next_idx] != '\0')
			dollar_all(info, &strs[i]);
		delete_quotes(strs[i]);
	}
}

static void	dollar_str(t_info *info, char **str_addr)
{
	int		dollar_next_idx;
	char	*str;

	str = *str_addr;
	dollar_next_idx = find_dollar_next_idx(str);
	if (dollar_next_idx != 0 && str[dollar_next_idx] != '\0')
		dollar_all(info, str_addr);
	delete_quotes(str);
}

void	expand_dollar(t_info *info, t_cmd *cmd)
{
	t_chunk	*cur_redirs;

	dollar_strs(info, cmd->strs);
	cur_redirs = cmd->redirs;
	while (cur_redirs != NULL)
	{
		if (cur_redirs->token != D_IN)
			dollar_str(info, &cur_redirs->str);
		cur_redirs = cur_redirs->next;
	}
}
