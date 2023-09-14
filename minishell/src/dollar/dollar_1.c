/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:11:40 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 22:07:41 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_dollar_next_idx(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '$')
			return (i + 1);
	return (0);
}

char	*delete_quotes(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			j = 0;
			while (str[i + j] == c)
				j++;
			ft_strlcpy(&str[i], &str[i + j], strlen(str) - i);
		}
		i++;
	}
	return (str);
}

char	**expander(t_info *info, char **strs)
{
	int		i;
	int		dollar_next_idx;

	i = -1;
	while (strs[++i] != NULL)
	{
		dollar_next_idx = find_dollar_next_idx(strs[i]);
		if (dollar_next_idx != 0 && strs[i][dollar_next_idx] != '\0')
			if (dollar_next_idx < 2 || \
				(dollar_next_idx >= 2 && strs[i][dollar_next_idx - 2] != '\''))
				dollar_all(info, &strs[i]);
		if (ft_strncmp(strs[0], "export", ft_strlen(strs[0]) - 1) != 0)
		{
			strs[i] = delete_quotes(strs[i], '\"');
			strs[i] = delete_quotes(strs[i], '\'');
		}
	}
	return (strs);
}

char	*expander_str(t_info *info, char *str)
{
	int		dollar_next_idx;

	dollar_next_idx = find_dollar_next_idx(str);
	if (dollar_next_idx != 0 && str[dollar_next_idx - 2] != '\'' && \
		str[dollar_next_idx] != '\0')
		dollar_all(info, &str);
	str = delete_quotes(str, '\"');
	str = delete_quotes(str, '\'');
	return (str);
}