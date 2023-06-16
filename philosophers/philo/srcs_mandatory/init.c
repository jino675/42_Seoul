/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:49:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/16 20:34:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

static int	sub_init_info(int ac, char **av, t_info *info)
{
	int	i;
	int	temp;

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
		if (sub_init_info(ac, av, info) == -1)
			return (-1);
	return (0);
}

static int	sub_init_vars(t_info *info, t_philo **philo, t_fork **fork)
{
	*fork = (t_fork *)malloc(sizeof(t_fork) * info->num_philo);
	if (*fork == NULL)
		return (-1);
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (*philo == NULL)
	{
		free(*fork);
		return (-1);
	}
	return (0);
}

int	init_vars(int ac, char **av, t_info *info, t_philo **philo)
{
	int		i;
	t_fork	*fork;

	if (init_info(ac, av, info) == -1)
		return (-1);
	if (sub_init_vars(info, philo, &fork) == -1)
		return (-1);
	i = -1;
	while (++i < info->num_philo)
		fork[i].is_using = 0;
	i = -1;
	while (++i < info->num_philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].fork = fork;
		(*philo)[i].number = i;
		(*philo)[i].last_eat.tv_sec = 0;
		(*philo)[i].last_eat.tv_usec = 0;
		(*philo)[i].last_sleep.tv_sec = 0;
		(*philo)[i].last_sleep.tv_usec = 0;
	}
	return (0);
}