/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:12:11 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/14 22:10:13 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dollar_digit(char **str_addr, int cur_idx)
{
	char	*str;
	char	*new_str;

	str = *str_addr;
	new_str = ft_substr(str, 0, cur_idx);
	ft_strattach(&new_str, &str[cur_idx + 2]);
	free(str);
	*str_addr = new_str;
	return (cur_idx);
}

static int	dollar_question(char **str_addr, int cur_idx)
{
	char	*str;
	char	*new_str;
	char	*nbr;

	str = *str_addr;
	new_str = ft_substr(str, 0, cur_idx);
	nbr = ft_itoa(g_global.error_num);
	ft_strattach(&new_str, nbr);
	cur_idx += ft_strlen(nbr);
	free(nbr);
	ft_strattach(&new_str, &str[cur_idx + 2]);
	free(*str_addr);
	*str_addr = new_str;
	return (cur_idx);
}

void	dollar_all(t_info *info, char **str_addr)
{
	int		i;
	char	*str;

	str = *str_addr;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && ft_isdigit(str[i + 1]) == 1)
			i = dollar_digit(&str, i);\
		else if (str[i] == '$' && str[i + 1] == '?')
			i = dollar_question(&str, i);
		else if (str[i] == '$' && str[i + 1] != '\0' && \
		(str[i + 1] != ' ' && (str[i + 1] != '\"' || str[i + 2] != '\0')))
			i = dollar_general(info, &str, i);
		else
			++i;
	}
	*str_addr = str;
}