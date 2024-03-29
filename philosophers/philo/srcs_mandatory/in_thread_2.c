/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_thread_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:39:04 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/13 18:37:24 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

int	check_completed(t_info *info, t_philo *philo);

static int	philo_take_fork(t_info *info, t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(&info->for_print);
	if (info->is_end == 1)
	{
		pthread_mutex_unlock(&info->for_print);
		return (-1);
	}
	dif_time = get_diftime(philo->last_eat, NULL);
	if (dif_time >= (long)info->time_die)
	{
		pthread_mutex_unlock(&info->for_print);
		return (-1);
	}
	dif_time = get_diftime(info->start_time, NULL);
	printf("%10ldms %3d has taken a fork\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
	return (0);
}

static int	philo_eat(t_info *info, t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(&info->for_print);
	if (info->is_end == 1)
	{
		pthread_mutex_unlock(&info->for_print);
		return (-1);
	}
	dif_time = get_diftime(philo->last_eat, NULL);
	if (dif_time >= (long)info->time_die)
	{
		pthread_mutex_unlock(&info->for_print);
		return (-1);
	}
	dif_time = get_diftime(info->start_time, philo);
	printf("%10ldms \033[0;32m%3d is eating\033[0m\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
	if (my_usleep(info, philo, info->time_eat) == -1)
		return (-1);
	if (info->num_eat != -1)
		if (check_completed(info, philo) == -1)
			return (-1);
	return (0);
}

static int	wait_fork(t_info *info, t_philo *philo, t_fork *fork)
{
	long	dif_time;

	while (1)
	{
		pthread_mutex_lock(&fork->mutex);
		if (fork->is_using == 0)
		{
			fork->is_using = 1;
			pthread_mutex_unlock(&fork->mutex);
			return (0);
		}
		pthread_mutex_unlock(&fork->mutex);
		dif_time = get_diftime(philo->last_eat, NULL);
		if (dif_time >= (long)info->time_die)
			return (-1);
		usleep(SLEEP_UNIT);
	}
}

static void	after_fork(t_fork *fork_1, t_fork *fork_2)
{
	if (fork_1 != NULL)
	{
		pthread_mutex_lock(&fork_1->mutex);
		fork_1->is_using = 0;
		pthread_mutex_unlock(&fork_1->mutex);
	}
	if (fork_2 != NULL)
	{
		pthread_mutex_lock(&fork_2->mutex);
		fork_2->is_using = 0;
		pthread_mutex_unlock(&fork_2->mutex);
	}
}

int	with_fork(t_info *info, t_philo *philo, t_fork *fork_1, t_fork *fork_2)
{
	if (wait_fork(info, philo, fork_1) == -1)
		return (-1);
	if (philo_take_fork(info, philo) == -1)
	{
		after_fork(fork_1, NULL);
		return (-1);
	}
	if (wait_fork(info, philo, fork_2) == -1)
	{
		after_fork(fork_1, NULL);
		return (-1);
	}
	if (philo_take_fork(info, philo) == -1)
	{
		after_fork(fork_1, fork_2);
		return (-1);
	}
	if (philo_eat(info, philo) == -1)
	{
		after_fork(fork_1, fork_2);
		return (-1);
	}
	after_fork(fork_1, fork_2);
	return (0);
}
