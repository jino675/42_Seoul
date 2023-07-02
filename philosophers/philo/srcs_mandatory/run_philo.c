/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/02 21:58:20 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

void	*in_thread(void *var);

static void	sub_run_philo(t_info *info, t_philo *philo)
{
	int		i;

	gettimeofday(&(info->start_time), NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].last_eat = info->start_time;
		printf("%10dms \033[0;34m%3d is thinking\033[0m\n", 0, philo[i].number);
	}
	i = -1;
	while (++i < info->num_philo / 2)
		pthread_create(&philo[i * 2].thread, NULL, in_thread, \
										(void *)&(philo[i * 2]));
	my_usleep(info->time_eat / 4);
	i = -1;
	while (++i < info->num_philo / 2)
		pthread_create(&philo[i * 2 + 1].thread, NULL, in_thread, \
										(void *)&(philo[i * 2 + 1]));
	if (info->num_philo % 2 == 1)
		pthread_create(&philo[info->num_philo - 1].thread, NULL, in_thread, \
									(void *)&(philo[info->num_philo - 1]));
}

int	run_philo(t_info *info, t_philo *philo, pthread_mutex_t *fork)
{
	int		i;

	sub_run_philo(info, philo);
	i = -1;
	while (++i < info->num_philo)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&fork[i]);
	pthread_mutex_destroy(&info->for_print);
	pthread_mutex_destroy(&info->for_count);
	return (0);
}

// long	dif_time;
// i = -1;
// while (++i < info->num_philo)
// {
// 	dif_time = (philo[i].last_eat.tv_sec - info->start_time.tv_sec) * 1000
// + ((long)philo[i].last_eat.tv_usec - (long)info->start_time.tv_usec) / 1000;
// 	printf("%3d ate %d times (%ld)ms\n", i, info->count_eat[i], dif_time);
// }