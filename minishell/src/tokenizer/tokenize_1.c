/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:07:14 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 19:17:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	distance_to_pair(char *line, int *cnt, char q)
{
	int	i;

	i = 1;
	++(*cnt);
	while (line[i] != '\0' && line[i] != q)
		++i;
	if (line[i] == q)
		++(*cnt);
	return (i);
}

int	check_quotes(char *line)
{
	int	i;
	int	s_cnt;
	int	d_cnt;

	s_cnt = 0;
	d_cnt = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\'')
			i += distance_to_pair(&line[i], &s_cnt, '\'');
		if (line[i] == '\"')
			i += distance_to_pair(&line[i], &d_cnt, '\"');
	}
	if ((s_cnt > 0 && s_cnt % 2 == 1) || (d_cnt > 0 && d_cnt % 2 == 1))
		return (0);
	return (1);
}