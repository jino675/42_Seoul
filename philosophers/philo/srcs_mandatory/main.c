/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:02:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/22 22:57:13 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

int		init_vars(int ac, char **av, t_info *info, t_philo **philo);
int		run_philo(t_info *info, t_philo *philo, pthread_mutex_t *fork);
void	free_vars(t_info *info, t_philo *philo, pthread_mutex_t *fork);

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (init_vars(ac, av, &info, &philo) == -1)
	{
		printf("something wrong!\n");
		return (1);
	}
	run_philo(&info, philo, philo[0].fork);
	free_vars(&info, philo, philo[0].fork);
	return (0);
}