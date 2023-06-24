/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:49:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/24 20:56:22 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

static int	sub_init_info(int ac, char **av, t_info *info)
{
	int	i;
	int	temp;

	info->num_eat = -1;
	info->is_died = 0;
	info->is_completed = 0;
	info->count_eat = NULL;
	i = 0;
	while (++i < ac)
	{
		temp = ft_atoi(av[i]);
		if (temp == -1)
			return (-1);
		else if (i == 1)
			info->num_philo = temp;
		else if (i == 2)
			info->time_die = temp;
		else if (i == 3)
			info->time_eat = temp;
		else if (i == 4)
			info->time_sleep = temp;
		else if (i == 5)
			info->num_eat = temp;
	}
	return (0);
}

static int	init_info(int ac, char **av, t_info *info)
{
	if (ac < 5 || ac > 6)
		return (-1);
	else if (ac == 5 || ac == 6)
	{
		if (sub_init_info(ac, av, info) == -1)
			return (-1);
		if (info->num_eat != -1)
		{
			info->count_eat = (int *)malloc(sizeof(int) * info->num_philo);
			if (info->count_eat == NULL)
				return (-1);
		}
	}
	return (0);
}

static int	sub_init_vars(t_info *info, t_philo **philo, pthread_mutex_t **fork)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (*philo == NULL)
	{
		if (info->count_eat != NULL)
			free(info->count_eat);
		return (-1);
	}
	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
															info->num_philo);
	if (*fork == NULL)
	{
		if (info->count_eat != NULL)
			free(info->count_eat);
		free(*philo);
		return (-1);
	}
	return (0);
}

int	init_vars(int ac, char **av, t_info *info, t_philo **philo)
{
	int					i;
	pthread_mutex_t		*fork;

	if (init_info(ac, av, info) == -1)
		return (-1);
	if (sub_init_vars(info, philo, &fork) == -1)
		return (-1);
	i = -1;
	while (++i < info->num_philo)
	{
		if (info->count_eat != NULL)
			info->count_eat[i] = 0;
		(*philo)[i].info = info;
		(*philo)[i].fork = fork;
		(*philo)[i].number = i;
		(*philo)[i].last_eat.tv_sec = 0;
		(*philo)[i].last_eat.tv_usec = 0;
	}
	return (0);
}