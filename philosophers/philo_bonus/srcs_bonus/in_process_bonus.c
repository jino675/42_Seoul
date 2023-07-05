/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:36:52 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/04 19:57:29 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

int	with_fork(t_info *info, t_philo *philo, sem_t *fork);

int	check_died(t_info *info, t_philo *philo)
{
	long	dif_time;

	dif_time = get_diftime(philo->last_eat, NULL);
	if (dif_time < (long)info->time_die)
		return (0);
	dif_time = get_diftime(info->start_time, NULL);
	sem_wait(info->for_print);
	printf("%10ldms \033[0;31m%3d died\033[0m\n", dif_time, philo->number);
	return (-1);
}

int	philo_sleep(t_info *info, t_philo *philo)
{
	long	dif_time;

	if (check_died(info, philo) == -1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	sem_wait(info->for_print);
	printf("%10ldms \033[0;93m%3d is sleeping\033[0m\n", dif_time, philo->number);
	sem_post(info->for_print);
	if (my_usleep(info, philo, info->time_sleep) == -1)
		return (-1);
	return (0);
}

int	philo_think(t_info *info, t_philo *philo)
{
	long	dif_time;

	if (check_died(info, philo) == -1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	sem_wait(info->for_print);
	printf("%10ldms \033[0;34m%3d is thinking\033[0m\n", dif_time, philo->number);
	sem_post(info->for_print);
	if (info->num_philo % 2 == 1 && info->time_sleep <= info->time_eat)
		if (my_usleep(info, philo, info->time_eat - info->time_sleep + 1) == -1)
			return (-1);
	return (0);
}

void	in_process(t_info *info, t_philo *philo, sem_t *fork)
{
	while (info->num_philo == 1)
	{
		if (my_usleep(info, philo, info->time_die) == -1)
			exit(0);
		if (check_died(info, philo) == -1)
			exit(0);
	}
	while (1)
	{
		if (with_fork(info, philo, fork) == -1)
			break ;
		if (philo_sleep(info, philo) == -1)
			break ;
		if (philo_think(info, philo) == -1)
			break ;
	}
	exit(0);
}
