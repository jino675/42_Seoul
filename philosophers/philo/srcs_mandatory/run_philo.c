/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/16 21:34:37 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

void	*run_thread(void *var)
{
	int				i;
	int				idx_1;
	int				idx_2;
	struct timeval	cur_time;
	long			dif_time;
	t_philo			*philo;

	philo = (t_philo *)var;
	i = -1;
	while (++i < 5)
	{
		gettimeofday(&cur_time, NULL);
		dif_time = (cur_time.tv_sec - philo->info->start_time.tv_sec) * 1000 \
				+ (cur_time.tv_usec - philo->info->start_time.tv_usec) / 1000;
		if (philo->number == 0)
			idx_1 = philo->info->num_philo - 1;
		else
			idx_1 = philo->number - 1;
		pthread_mutex_lock(&philo->fork[idx_1].mutex);
		idx_2 = philo->number;
		pthread_mutex_lock(&philo->fork[idx_2].mutex);
		printf("no.%d : i = %d, %ldms\n", philo->number, i, dif_time);
		pthread_mutex_unlock(&philo->fork[idx_1].mutex);
		pthread_mutex_unlock(&philo->fork[idx_2].mutex);
	}
	return (NULL);
}

int	run_philo(t_info *info, t_philo *philo)
{
	int	i;

	printf("num : %d, time_die : %d, time_eat : %d, time_sleep : %d\n", info->num_philo, info->time_die, info->time_eat, info->time_sleep);
	gettimeofday(&(info->start_time), NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_init(&philo[0].fork[i].mutex, NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_create(&philo[i].thread, NULL, run_thread, (void *)&(philo[i]));
	i = -1;
	while (++i < info->num_philo)
		pthread_join(philo[i].thread, NULL);
	return (0);
}
