/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:49:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/05 17:48:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

static int	sub_init_info(int ac, char **av, t_info *info)
{
	int	i;
	int	temp;

	info->num_eat = -1;
	info->is_end = 0;
	info->count = 0;
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
	int	i;

	if (sub_init_info(ac, av, info) == -1)
		return (free_vars(info, NULL, NULL));
	info->count_eat = (int *)malloc(sizeof(int) * info->num_philo);
	if (info->count_eat == NULL)
		return (free_vars(info, NULL, NULL));
	i = -1;
	while (++i < info->num_philo)
		info->count_eat[i] = 0;
	return (0);
}

static int	sub_init_vars(t_info *info, t_philo **philo, t_fork **fork)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (*philo == NULL)
		return (free_vars(info, NULL, NULL));
	*fork = (t_fork *)malloc(sizeof(t_fork) * info->num_philo);
	if (*fork == NULL)
		return (free_vars(info, *philo, NULL));
	i = -1;
	while (++i < info->num_philo)
	{
		(*fork)[i].number = i;
		(*fork)[i].is_using = 0;
	}
	return (0);
}

static int	init_mutex(t_info *info, t_philo *philo, t_fork *fork)
{
	int	i;

	if (pthread_mutex_init(&info->for_print, NULL) != 0)
		return (free_vars(info, philo, fork));
	if (pthread_mutex_init(&info->for_count, NULL) != 0)
	{
		pthread_mutex_destroy(&info->for_print);
		return (free_vars(info, philo, fork));
	}
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&fork[i].mutex, NULL) != 0)
		{
			while (--i > -1)
				pthread_mutex_destroy(&fork[i].mutex);
			pthread_mutex_destroy(&info->for_print);
			pthread_mutex_destroy(&info->for_count);
			return (free_vars(info, philo, fork));
		}
	}
	return (0);
}

int	init_vars(int ac, char **av, t_philo **philo)
{
	int		i;
	t_info	*info;
	t_fork	*fork;

	if (ac < 5 || ac > 6)
		return (-1);
	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		return (-1);
	if (init_info(ac, av, info) == -1)
		return (-1);
	if (sub_init_vars(info, philo, &fork) == -1)
		return (-1);
	if (init_mutex(info, *philo, fork) == -1)
		return (-1);
	i = -1;
	while (++i < info->num_philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].fork = fork;
		(*philo)[i].number = i;
		(*philo)[i].idx_1 = i + (info->num_philo * (i == 0) - 1) * (i % 2 == 1);
		(*philo)[i].idx_2 = i + (info->num_philo * (i == 0) - 1) * (i % 2 == 0);
	}
	return (0);
}

	// info->list = (int *)malloc(sizeof(int) * (info->num_philo));
	// if (info->list == NULL)
	// {
	// 	free_vars(info, NULL, NULL);
	// 	return (-1);
	// }
		// if (i % 2 == 0 && i != info->num_philo - 1)
		// 	info->list[i] = 1;
		// else
		// 	info->list[i] = 0;