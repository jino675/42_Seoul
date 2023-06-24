/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/24 22:36:00 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

static long	get_diftime(struct timeval ref_time, t_philo *philo)
{
	struct timeval	cur_time;
	long			dif_time;

	gettimeofday(&cur_time, NULL);
	if (philo != NULL)
		philo->last_eat = cur_time;
	dif_time = (cur_time.tv_sec - ref_time.tv_sec) * 1000 \
			+ ((long)cur_time.tv_usec - (long)ref_time.tv_usec) / 1000;
	return (dif_time);
}

static int	is_died(t_philo *philo)
{
	long	dif_time;
	t_info	*info;

	info = philo->info;
	dif_time = get_diftime(philo->last_eat, NULL);
	if (dif_time >= (long)info->time_die)
	{
		// printf("%ld %ld\n", dif_time, (long)info->time_die);
		// printf("%d's dif_time was %10ldms\n\n", philo->number, dif_time);
		if (info->is_died != 0 || info->is_completed != 0)
			return (1);
		info->is_died = philo->number;
		return (1);
	}
	return (0);
}

static int	is_completed(t_philo *philo)
{
	int		i;
	t_info	*info;

	info = philo->info;
	++info->count_eat[philo->number];
	i = -1;
	while (++i < info->num_philo)
		if (info->count_eat[i] != info->num_eat)
			return (0);
	if (info->is_died != 0 || info->is_completed != 0)
		return (1);
	info->is_completed = 1;
	return (1);
}

static int	sub_with_fork(t_philo *philo)
{
	long			dif_time;
	t_info			*info;

	info = philo->info;
	if (is_died(philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	if (info->is_died != 0 || info->is_completed != 0)
		return (-1);
	pthread_mutex_lock(&info->print);
	printf("%10ldms %d has taken a fork\n\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->print);

	if (is_died(philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, philo);
	if (info->is_died != 0 || info->is_completed != 0)
		return (-1);
	pthread_mutex_lock(&info->print);
	printf("%10ldms %d is eating\n\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->print);
	usleep(philo->info->time_eat * 950);
	if (info->num_eat != -1)
		if (is_completed(philo) == 1)
			return (-1);

	if (is_died(philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	if (info->is_died != 0 || info->is_completed != 0)
		return (-1);
	pthread_mutex_lock(&info->print);
	printf("%10ldms %d is sleeping\n\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->print);
	return (0);
}

static int	with_fork(t_philo *philo, int *idx)
{
	if (is_died(philo) == 1)
		return (-1);
	pthread_mutex_lock(&philo->fork[idx[0]]);
	pthread_mutex_lock(&philo->fork[idx[1]]);
	if (sub_with_fork(philo) == -1)
	{
		pthread_mutex_unlock(&philo->fork[idx[0]]);
		pthread_mutex_unlock(&philo->fork[idx[1]]);
		return (-1);
	}
	pthread_mutex_unlock(&philo->fork[idx[0]]);
	pthread_mutex_unlock(&philo->fork[idx[1]]);
	usleep(philo->info->time_sleep * 1000);
	return (0);
}

void	*run_thread(void *var)
{
	int				idx[2];
	t_philo			*philo;
	t_info			*info;
	long			dif_time;

	philo = (t_philo *)var;
	info = philo->info;
	if (philo->number == 0)
		idx[0] = philo->info->num_philo - 1;
	else
		idx[0] = philo->number - 1;
	idx[1] = philo->number;
	while (1)
	{
		if (with_fork(philo, idx) == -1)
			break ;
		if (is_died(philo) == 1)
			break ;
		dif_time = get_diftime(info->start_time, NULL);
		if (info->is_died != 0 || info->is_completed != 0)
			break ;
		pthread_mutex_lock(&info->print);
		printf("%10ldms %d is thinking\n\n", dif_time, philo->number);
		pthread_mutex_unlock(&info->print);
	}
	return (NULL);
}

int	run_philo(t_info *info, t_philo *philo, pthread_mutex_t *fork)
{
	int		i;
	long	dif_time;

	pthread_mutex_init(&info->print, NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		printf("%10dms %d is thinking\n\n", 0, i);
		pthread_mutex_init(&fork[i], NULL);
	}
	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].last_eat = info->start_time;
		pthread_create(&philo[i].thread, NULL, run_thread, (void *)&(philo[i]));
	}
	while (1)
	{
		if (info->is_died != 0 || info->is_completed != 0)
		{
			dif_time = get_diftime(info->start_time, NULL);
			if (info->is_died != 0)
				printf("%10ldms %d died\n\n", dif_time, info->is_died);
			else if (info->is_completed != 0)
				printf("%10ldms simulation is completed\n\n", dif_time);
			break ;
		}
	}
	i = -1;
	while (++i < info->num_philo)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&fork[i]);
	return (0);
}
