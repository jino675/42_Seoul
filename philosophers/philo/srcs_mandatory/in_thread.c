/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:36:52 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/13 18:36:05 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

int	with_fork(t_info *info, t_philo *philo, \
		t_fork *fork_1, t_fork *fork_2);

int	check_completed(t_info *info, t_philo *philo)
{
	++info->count_eat[philo->number];
	if (info->count_eat[philo->number] == info->num_eat)
	{
		pthread_mutex_lock(&info->for_count);
		++info->count;
		if (info->count != info->num_philo)
		{
			pthread_mutex_unlock(&info->for_count);
			return (0);
		}
		pthread_mutex_lock(&info->for_print);
		if (info->is_end == 1)
		{
			pthread_mutex_unlock(&info->for_print);
			pthread_mutex_unlock(&info->for_count);
			return (-1);
		}
		info->is_end = 1;
		printf("\n******** simulation is completed ********\n\n");
		pthread_mutex_unlock(&info->for_print);
		pthread_mutex_unlock(&info->for_count);
		return (-1);
	}
	return (0);
}

static int	philo_sleep(t_info *info, t_philo *philo)
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
	printf("%10ldms \033[0;93m%3d is sleeping\033[0m\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
	if (my_usleep(info, philo, info->time_sleep) == -1)
		return (-1);
	return (0);
}

static int	philo_think(t_info *info, t_philo *philo)
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
	printf("%10ldms \033[0;36m%3d is thinking\033[0m\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
	if (info->time_think != -1)
		if (my_usleep(info, philo, info->time_think) == -1)
			return (-1);
	return (0);
}

static void	philo_die(t_info *info, t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(&info->for_print);
	if (info->is_end == 1)
	{
		pthread_mutex_unlock(&info->for_print);
		return ;
	}
	info->is_end = 1;
	dif_time = get_diftime(info->start_time, NULL);
	printf("%10ldms \033[0;31m%3d died\033[0m\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->for_print);
}

void	*in_thread(void *var)
{
	t_info			*info;
	t_philo			*philo;

	philo = (t_philo *)var;
	info = philo->info;
	if (info->num_philo > 1 && philo->number % 2 == 1)
		my_usleep(info, philo, info->time_eat / 4);
	else if (info->num_philo > 1 && philo->number == info->num_philo - 1)
		my_usleep(info, philo, info->time_eat + info->time_eat / 4);
	while (1)
	{
		if (with_fork(info, philo, &philo->fork[philo->idx_1], \
								&philo->fork[philo->idx_2]) == -1)
			break ;
		if (philo_sleep(info, philo) == -1)
			break ;
		if (philo_think(info, philo) == -1)
			break ;
	}
	philo_die(info, philo);
	return (NULL);
}
