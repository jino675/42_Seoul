/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_thread_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:39:04 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/02 20:42:48 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

int	check_died(t_info *info, t_philo *philo);
int	check_completed(t_info *info, t_philo *philo);

static int	philo_take_fork(t_info *info, t_philo *philo)
{
	long	dif_time;

	if (check_died(info, philo) == -1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	pthread_mutex_lock(&info->for_print);
	if (info->is_end == 1)
	{
		pthread_mutex_unlock(&info->for_print);
		return (-1);
	}
	printf("%10ldms %3d has taken a fork\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
	return (0);
}

static int	philo_eat(t_info *info, t_philo *philo)
{
	long	dif_time;

	if (check_died(info, philo) == -1)
		return (-1);
	dif_time = get_diftime(info->start_time, philo);
	pthread_mutex_lock(&info->for_print);
	if (info->is_end == 1)
	{
		pthread_mutex_unlock(&info->for_print);
		return (-1);
	}
	printf("%10ldms \033[0;32m%3d is eating\033[0m\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
	my_usleep(info->time_eat);
	if (check_completed(info, philo) == -1)
		return (-1);
	return (0);
}

int	with_fork(t_info *info, t_philo *philo, \
		pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	pthread_mutex_lock(fork_1);
	if (philo_take_fork(info, philo) == -1)
	{
		pthread_mutex_unlock(fork_1);
		return (-1);
	}
	pthread_mutex_lock(fork_2);
	if (philo_take_fork(info, philo) == -1)
	{
		pthread_mutex_unlock(fork_1);
		pthread_mutex_unlock(fork_2);
		return (-1);
	}
	if (philo_eat(info, philo) == -1)
	{
		pthread_mutex_unlock(fork_1);
		pthread_mutex_unlock(fork_2);
		return (-1);
	}
	pthread_mutex_unlock(fork_1);
	pthread_mutex_unlock(fork_2);
	return (0);
}

	// if (info->list[philo->number] != 1)
	// 	wait_eating(info, philo);
	// info->list[philo->number] = 2;

// static void	wait_eating(t_info *info, t_philo *philo)
// {
// 	while (1)
// 	{
// 		if (info->is_end == 1)
// 			return ;
// 		if (info->list[philo->left] == 2)
// 		{
// 			info->list[philo->left] = 0;
// 			info->list[philo->number] = 1;
// 			return ;
// 		}
// 		usleep(SLEEP_UNIT);
// 	}
// }