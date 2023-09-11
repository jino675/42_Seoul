/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:30 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/11 14:36:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	t_info	info;

	if (ac != 1 || av[1] != NULL)
	{
		printf("I don't need any arguments!\n");
		exit(0);
	}
	initialize(&info, ev);
	minishell(&info);
	return (0);
}