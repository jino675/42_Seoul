/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/23 17:01:38 by jiryu            ###   ########.fr       */
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
		printf("%ld %ld\n", dif_time, (long)info->time_die);
		printf("%d's dif_time was %10ldms\n\n", philo->number, dif_time);
		dif_time = get_diftime(info->start_time, NULL);
		if (info->is_died == 1 || info->is_completed == 1)
			return (1);
		printf("%10ldms %d died\n\n", dif_time, philo->number);
		info->is_died = 1;
		return (1);
	}
	return (0);
}

static void	check_completed(t_philo *philo)
{
	int		i;
	t_info	*info;

	info = philo->info;
	if (info->num_eat == -1)
		return ;
	++info->count_eat[philo->number];
	i = -1;
	while (++i < info->num_philo)
		if (info->count_eat[i] != info->num_eat)
			return ;
	if (info->is_died == 1 || info->is_completed == 1)
		return ;
	printf("simulation is completed\n\n");
	info->is_completed = 1;
	usleep(10 * 1000 * 1000);
}

static int	sub_with_fork(t_philo *philo)
{
	long			dif_time;
	t_info			*info;

	info = philo->info;
	if (is_died(philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	if (info->is_died == 1 || info->is_completed == 1)
		return (-1);
	printf("%10ldms %d has taken a fork\n\n", dif_time, philo->number);

	if (is_died(philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, philo);
	if (info->is_died == 1 || info->is_completed == 1)
		return (-1);
	printf("%10ldms %d is eating\n\n", dif_time, philo->number);
	usleep(philo->info->time_eat * 1000);
	check_completed(philo);

	if (is_died(philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	if (info->is_died == 1 || info->is_completed == 1)
		return (-1);
	printf("%10ldms %d is sleeping\n\n", dif_time, philo->number);
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
		if (info->is_died == 1 || info->is_completed == 1)
			break ;
		printf("%10ldms %d is thinking\n\n", dif_time, philo->number);
	}
	return (NULL);
}

int	run_philo(t_info *info, t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	gettimeofday(&(info->start_time), NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		printf("%10dms %d is thinking\n\n", 0, i);
		pthread_mutex_init(&fork[i], NULL);
		philo[i].last_eat = info->start_time;
	}
	i = -1;
	while (++i < info->num_philo)
		pthread_create(&philo[i].thread, NULL, run_thread, (void *)&(philo[i]));
	i = -1;
	while (++i < info->num_philo)
		pthread_detach(philo[i].thread);
	while (1)
		if (info->is_died == 1 || info->is_completed == 1)
			break ;
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&fork[i]);
	return (0);
}
