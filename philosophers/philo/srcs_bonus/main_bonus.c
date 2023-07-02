/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:02:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/02 18:53:05 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

int		init_vars(int ac, char **av, t_info **info);
int		run_philo(t_info *info, t_philo *philo);

int	main(int ac, char **av)
{
	t_info	*info;

	if (init_vars(ac, av, &info) == -1)
	{
		printf("something wrong!\n");
		return (1);
	}
	run_philo(info, &info->philo);
	free_vars(info);
	return (0);
}
