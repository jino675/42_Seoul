/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:39:04 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/08 22:14:03 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

static void	philo_take_fork(t_info *info, t_philo *philo)
{
	long	dif_time;

	sem_wait(info->for_print);
	dif_time = get_diftime(info->start_time, NULL);
	printf("%10ldms %3d has taken a fork\n", dif_time, philo->number);
	sem_post(info->for_print);
}

static void	philo_eat(t_info *info, t_philo *philo)
{
	long	dif_time;

	sem_wait(info->for_print);
	dif_time = get_diftime(info->start_time, philo);
	printf("%10ldms \033[0;32m%3d is eating\033[0m\n", dif_time, philo->number);
	sem_post(info->for_print);
	my_usleep(info->time_eat);
	++philo->count_eat;
	if (philo->count_eat == info->num_eat)
		sem_post(info->for_count);
}

int	with_fork(t_info *info, t_philo *philo, sem_t *fork)
{
	sem_wait(fork);
	philo_take_fork(info, philo);
	sem_wait(fork);
	philo_take_fork(info, philo);
	philo_eat(info, philo);
	sem_post(fork);
	sem_post(fork);
	return (0);
}
