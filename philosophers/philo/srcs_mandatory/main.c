/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:02:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/05 16:58:38 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

int	init_vars(int ac, char **av, t_philo **philo);
int	run_philo(t_info *info, t_philo *philo, t_fork *fork);

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (init_vars(ac, av, &philo) == -1)
	{
		printf("something is wrong!\n");
		return (1);
	}
	run_philo(philo[0].info, philo, philo[0].fork);
	free_vars(philo[0].info, philo, philo[0].fork);
	system("leaks philo");
	return (0);
}
