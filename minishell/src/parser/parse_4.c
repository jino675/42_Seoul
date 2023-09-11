/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:08:30 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 22:21:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	(*builtin_arr(char *str))(t_info *info, t_cmd *cmd)
{
	if (str != NULL)
	{
		if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_echo);
		else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_cd);
		else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_pwd);
		else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_export);
		else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_unset);
		else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_env);
		else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
			return (my_exit);
	}
	return (NULL);
}

t_cmd	*cmd_new(char **strs, int num_redirs, t_chunk *redirs)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (new_cmd == NULL)
		return (0);
	new_cmd->strs = strs;
	new_cmd->builtin = builtin_arr(strs[0]);
	new_cmd->hd_file_name = NULL;
	new_cmd->num_redirs = num_redirs;
	new_cmd->redirs = redirs;
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	return (new_cmd);
}

void	chunk_clear_print_error(int code, t_info *info, t_chunk *chunk_list)
{
	chunk_list_clear(&chunk_list);
	print_error(code, info);
}

void	cmd_list_push(t_cmd **list, t_cmd *new_cmd)
{
	t_cmd	*cur_cmd;

	cur_cmd = *list;
	if (*list == NULL)
	{
		*list = new_cmd;
		return ;
	}
	while (cur_cmd->next != NULL)
		cur_cmd = cur_cmd->next;
	cur_cmd->next = new_cmd;
	new_cmd->prev = cur_cmd;
}