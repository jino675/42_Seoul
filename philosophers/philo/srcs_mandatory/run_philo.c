/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/08 19:24:11 by jiryu            ###   ########.fr       */
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
		printf("%10dms \033[0;36m%3d is thinking\033[0m\n", 0, philo[i].number);
	}
	i = -1;
	while (++i < info->num_philo / 2)
		pthread_create(&philo[i * 2].thread, NULL, in_thread, \
										(void *)&(philo[i * 2]));
	i = -1;
	while (++i < info->num_philo / 2)
		pthread_create(&philo[i * 2 + 1].thread, NULL, in_thread, \
										(void *)&(philo[i * 2 + 1]));
	if (info->num_philo % 2 == 1)
		pthread_create(&philo[info->num_philo - 1].thread, NULL, in_thread, \
									(void *)&(philo[info->num_philo - 1]));
}

int	run_philo(t_info *info, t_philo *philo, t_fork *fork)
{
	int		i;

	sub_run_philo(info, philo);
	i = -1;
	while (++i < info->num_philo)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&fork[i].mutex);
	pthread_mutex_destroy(&info->for_print);
	pthread_mutex_destroy(&info->for_count);
	return (0);
}
