/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:29:46 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/22 20:25:19 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_not_ev(t_info *info, t_cmd *cmd);
int		get_ev_len(char *str);

static int	is_error(t_cmd *cmd)
{
	int		i;

	if (cmd->strs[1] == NULL)
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (cmd->strs[1][++i] != '\0')
	{
		if (cmd->strs[1][i] == '/' || cmd->strs[1][i] == '-' || \
			cmd->strs[1][i] == '=' || cmd->strs[1][i] == '+' || \
			cmd->strs[1][i] == '@' || cmd->strs[1][i] == '#' || \
			cmd->strs[1][i] == '%' || cmd->strs[1][i] == '^')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(cmd->strs[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	search_ev(char **ev, char *str)
{
	int	i;
	int	ev_len;
	int	str_len;

	str_len = ft_strlen(str);
	i = -1;
	while (ev[++i] != NULL)
	{
		ev_len = get_ev_len(ev[i]);
		if (str_len == ev_len && ft_strncmp(ev[i], str, ev_len) == 0)
		{
			ev[i][0] = '\0';
			return (1);
		}
	}
	return (0);
}

static void	get_cnt_ev(char **ev, char **strs, int *ev_size, int *unset_cnt)
{
	int	i;

	i = 0;
	while (ev[i] != NULL)
		++i;
	*ev_size = i + 1;
	*unset_cnt = 0;
	i = 0;
	while (strs[++i] != NULL)
		*unset_cnt += search_ev(ev, strs[i]);
}

static void	unset_ev(t_info *info, t_cmd *cmd)
{
	int		i;
	int		j;
	int		ev_size;
	int		unset_cnt;
	char	**new_ev;

	get_cnt_ev(info->ev, cmd->strs, &ev_size, &unset_cnt);
	new_ev = (char **)ft_calloc(ev_size - unset_cnt, sizeof(char *));
	i = -1;
	j = -1;
	while (info->ev[++i] != NULL)
	{
		if (info->ev[i][0] != '\0')
			new_ev[++j] = info->ev[i];
		else
			free(info->ev[i]);
	}
	free(info->ev);
	info->ev = new_ev;
}

int	my_unset(t_info *info, t_cmd *cmd)
{
	if (is_error(cmd) == 1)
		return (EXIT_FAILURE);
	unset_ev(info, cmd);
	unset_not_ev(info, cmd);
	return (EXIT_SUCCESS);
}
