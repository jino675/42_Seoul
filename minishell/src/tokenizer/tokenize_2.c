/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:09:31 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 19:19:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	return (i);
}

static int	skip_quotes(char *str, char del)
{
	int	i;

	i = 0;
	if (str[i] == del)
	{
		++i;
		while (str[i] != del)
			++i;
		++i;
	}
	return (i);
}

static int	read_words(char *str, t_chunk **chunk_list)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && check_token(str[i]) == 0)
	{
		i += skip_quotes(&str[i], '\'');
		i += skip_quotes(&str[i], '\"');
		if (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
			break ;
		else
			i++;
	}
	if (make_new_chunk(ft_substr(str, 0, i), 0, chunk_list) == 0)
		return (-1);
	return (i);
}

int	read_token(t_info *info)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (info->args[i] != '\0')
	{
		i += count_white_spaces(&info->args[i]);
		if (check_token(info->args[i]) != 0)
			ret = add_token(&info->args[i], &info->chunk_list);
		else
			ret = read_words(&info->args[i], &info->chunk_list);
		if (ret < 0)
			return (0);
		i += ret;
	}
	return (1);
}