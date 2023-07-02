/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_thread_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:39:04 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/02 18:06:53 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

int	check_died(t_info *info, t_philo *philo);

static int	philo_take_fork(t_info *info, t_philo *philo)
{
	long	dif_time;

	if (check_died(info, philo) == -1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	sem_wait(info->for_print);
	printf("%10ldms %3d has taken a fork\n", dif_time, philo->number);
	sem_post(info->for_print);
	return (0);
}

static int	philo_eat(t_info *info, t_philo *philo)
{
	long	dif_time;

	if (check_died(info, philo) == -1)
		return (-1);
	dif_time = get_diftime(info->start_time, philo);
	sem_wait(info->for_print);
	printf("%10ldms \033[0;32m%3d is eating\033[0m\n", dif_time, philo->number);
	sem_post(info->for_print);
	my_usleep(info->time_eat);
	++philo->count_eat;
	if (philo->count_eat == info->num_eat)
		sem_post(info->for_count);
	return (0);
}

int	with_fork(t_info *info, t_philo *philo, sem_t *fork)
{
	sem_wait(fork);
	if (philo_take_fork(info, philo) == -1)
	{
		sem_post(fork);
		return (-1);
	}
	sem_wait(fork);
	if (philo_take_fork(info, philo) == -1)
	{
		sem_post(fork);
		sem_post(fork);
		return (-1);
	}
	if (philo_eat(info, philo) == -1)
	{
		sem_post(fork);
		sem_post(fork);
		return (-1);
	}
	sem_post(fork);
	sem_post(fork);
	return (0);
}
