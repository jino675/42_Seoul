/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/29 00:01:23 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

static long	get_udiftime(struct timeval ref_time, t_philo *philo)
{
	struct timeval	cur_time;
	long			dif_time;

	gettimeofday(&cur_time, NULL);
	if (philo != NULL)
		philo->last_eat = cur_time;
	dif_time = (cur_time.tv_sec - ref_time.tv_sec) * 1000 * 1000 \
			+ ((long)cur_time.tv_usec - (long)ref_time.tv_usec);
	return (dif_time);
}

static void	my_usleep(long time)
{
	struct timeval	init_time;
	long			dif_time;

	gettimeofday(&init_time, NULL);
	while (1)
	{
		usleep(500);
		dif_time = get_udiftime(init_time, NULL);
		if (dif_time >= time * 1000)
			break ;
	}
}

static void	wait_eating(t_info *info, t_philo *philo)
{
	int	idx_1;
	int	idx_2;

	if (info->list[philo->number] == 1)
		return ;
	if (philo->number != 0)
		idx_1 = philo->number - 1;
	else
		idx_1 = info->num_philo - 1;
	if (philo->number != info->num_philo - 1)
		idx_2 = philo->number + 1;
	else
		idx_2 = 0;
	while (1)
	{
		// i = -1;
		// while (++i < info->num_philo / 2)
		// 	printf("%d ", info->cur[i]);
		if (info->is_died != 0 || info->is_completed != 0)
			return ;
		if (info->list[idx_1] == 2 && \
				(info->list[idx_2] == 0 || info->list[idx_2] == 2))
		{
			info->list[idx_1] = 0;
			info->list[philo->number] = 1;
			return ;
		}
		// if (info->count == 0)
		// 	if (info->list[philo->number] == 1)
		// 		return ;
		
		// i = -1;
		// while (++i < info->num_philo / 2)
		// 	if (philo->number == info->cur[i])
		// 		return ;
		usleep(1000);
	}
}

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

static int	is_died(t_info *info, t_philo *philo)
{
	long	dif_time;

	dif_time = get_diftime(philo->last_eat, NULL);
	if (dif_time >= (long)info->time_die)
	{
		dif_time = get_diftime(info->start_time, NULL);
		pthread_mutex_lock(&info->print);
		if (info->is_died != 0 || info->is_completed != 0)
		{
			pthread_mutex_unlock(&info->print);
			return (1);
		}
		info->is_died = philo->number;
		printf("%10ldms %d died\n\n", dif_time, info->is_died);
		pthread_mutex_unlock(&info->print);
		return (1);
	}
	return (0);
}

static int	is_completed(t_info *info, t_philo *philo)
{
	int		i;
	long	dif_time;

	++info->count_eat[philo->number];
	i = -1;
	// while (++i < info->num_philo)
	// 	if (info->count_eat[i] < info->num_eat)
			return (0);
	dif_time = get_diftime(info->start_time, NULL);
	pthread_mutex_lock(&info->print);
	if (info->is_died != 0 || info->is_completed != 0)
	{
		pthread_mutex_unlock(&info->print);
		return (1);
	}
	info->is_completed = 1;
	printf("%10ldms simulation is completed\n\n", dif_time);
	pthread_mutex_unlock(&info->print);
	return (1);
}

static int	sub_with_fork(t_info *info, t_philo *philo)
{
	long			dif_time;

	if (is_died(info, philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, NULL);
	pthread_mutex_lock(&info->print);
	if (info->is_died != 0 || info->is_completed != 0)
	{
		pthread_mutex_unlock(&info->print);
		return (-1);
	}		
	
	// printf("cur num = %d, cur state = %d\n", philo->number, info->list[philo->number]);
		
	printf("%10ldms %d has taken a fork\n\n", dif_time, philo->number);
	pthread_mutex_unlock(&info->print);

	if (is_died(info, philo) == 1)
		return (-1);
	dif_time = get_diftime(info->start_time, philo);
	pthread_mutex_lock(&info->print);
	if (info->is_died != 0 || info->is_completed != 0)
	{
		pthread_mutex_unlock(&info->print);
		return (-1);
	}
	printf("%10ldms %d is eating (%dth)\n\n", dif_time, philo->number, info->count_eat[philo->number] + 1);
	pthread_mutex_unlock(&info->print);
	my_usleep(philo->info->time_eat);
	// if (info->num_eat != -1)
		if (is_completed(info, philo) == 1)
			return (-1);
	return (0);
}

static int	with_fork(t_info *info, t_philo *philo, t_fork *fork, int *idx)
{
	// int	i;

	wait_eating(info, philo);
	if (is_died(info, philo) == 1)
		return (-1);
	// if (fork[idx[0]].is_using == 1)
	// 	usleep(1000);
	pthread_mutex_lock(&fork[idx[0]].mutex);
	// fork[idx[0]].is_using = 1;
	// if (fork[idx[1]].is_using == 1)
	// 	usleep(1000);
	// printf("%d is taken by %d\n", idx[0], philo->number);
	pthread_mutex_lock(&fork[idx[1]].mutex);
	// fork[idx[1]].is_using = 1;
	// printf("%d is taken by %d\n", idx[1], philo->number);
	if (sub_with_fork(info, philo) == -1)
	{
		pthread_mutex_unlock(&fork[idx[0]].mutex);
		// fork[idx[0]].is_using = 0;
		pthread_mutex_unlock(&fork[idx[1]].mutex);
		// fork[idx[1]].is_using = 0;
		return (-1);
	}
	pthread_mutex_unlock(&fork[idx[0]].mutex);
	// fork[idx[0]].is_using = 0;
	pthread_mutex_unlock(&fork[idx[1]].mutex);
	// fork[idx[1]].is_using = 0;

	info->list[philo->number] = 2;
	// pthread_mutex_lock(&info->check);
	// ++info->count;
	// if (info->count == info->num_philo / 2)
	// {
	// 	i = -1;
	// 	info->list[info->num_philo] = info->list[0];
	// 	while (++i < info->num_philo)
	// 	{
	// 		if (info->list[i + 1] == 1)
	// 			info->list[i] = 1;
	// 		else
	// 			info->list[i] = 0;
	// 	}
	// 	info->count = 0;
	// }
	
	// if (info->count == 0)
	// {
	// 	i = -1;
	// 	while (++i < info->num_philo)
	// 		printf("%d : %d \n", i, info->list[i]);
	// 	printf("cur num = %d, cur count = %d (new)\n", philo->number, info->count);
	// }
	// printf(", cur num = %d, cur count = %d (new)\n", philo->number, info->count);
	// pthread_mutex_unlock(&info->check);
	return (0);
}

void	*run_thread(void *var)
{
	int				idx[3];
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
	// if (philo->number % 2 == 1)
	// {
	// 	idx[2] = idx[0];
	// 	idx[0] = idx[1];
	// 	idx[1] = idx[2];
	// }7000000
	while (1)
	{
		if (with_fork(info, philo, philo->fork, idx) == -1)
			break ;

		if (is_died(info, philo) == 1)
			break ;
		dif_time = get_diftime(info->start_time, NULL);
		pthread_mutex_lock(&info->print);
		if (info->is_died != 0 || info->is_completed != 0)
		{
			pthread_mutex_unlock(&info->print);
			break ;
		}
		printf("%10ldms %d is sleeping\n\n", dif_time, philo->number);
		pthread_mutex_unlock(&info->print);
		my_usleep(info->time_sleep);

		if (is_died(info, philo) == 1)
			break ;
		dif_time = get_diftime(info->start_time, NULL);
		pthread_mutex_lock(&info->print);
		if (info->is_died != 0 || info->is_completed != 0)
		{
			pthread_mutex_unlock(&info->print);
			break ;
		}
		printf("%10ldms %d is thinking\n\n", dif_time, philo->number);
		pthread_mutex_unlock(&info->print);
	}
	return (NULL);
}

int	run_philo(t_info *info, t_philo *philo, t_fork *fork)
{
	int		i;

	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->check, NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_init(&fork[i].mutex, NULL);
	gettimeofday(&(info->start_time), NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].last_eat = info->start_time;
		printf("%10dms %d is thinking\n\n", 0, i);
	}
	i = -1;
	while (++i < info->num_philo / 2)
		pthread_create(&philo[i * 2].thread, NULL, run_thread, \
										(void *)&(philo[i * 2]));
	i = -1;
	while (++i < info->num_philo / 2)
		pthread_create(&philo[i * 2 + 1].thread, NULL, run_thread, \
										(void *)&(philo[i * 2 + 1]));
	if (info->num_philo % 2 == 1)
		pthread_create(&philo[info->num_philo - 1].thread, NULL, run_thread, \
									(void *)&(philo[info->num_philo - 1]));
	i = -1;
	while (++i < info->num_philo)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		long dif_time = (philo[i].last_eat.tv_sec - info->start_time.tv_sec) * 1000 \
			+ ((long)philo[i].last_eat.tv_usec - (long)info->start_time.tv_usec) / 1000;
		printf("%d ate %d times (%ld)ms\n", i, info->count_eat[i], dif_time);
	}
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&fork[i].mutex);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->check);
	return (0);
}
