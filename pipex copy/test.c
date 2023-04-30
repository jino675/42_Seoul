/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:49:27 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/27 18:49:01 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"


char	**split_quote(char const *s, char c);
void	error_exit(char const *msg, t_etc *e);

int main(int ac, char **av)
{
	int		i;
	char	**strs;

	strs = split_quote(av[1], ' ');
	i = -1;
	while (strs[++i] != NULL)
	{
		printf("%s\n", strs[i]);
	}
	return (0);
}
