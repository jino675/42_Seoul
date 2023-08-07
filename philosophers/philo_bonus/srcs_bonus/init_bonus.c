/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:49:45 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/08 16:55:04 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

static int	sub_init_info(int ac, char **av, t_info *info)
{
	int	i;
	int	temp;

	info->num_eat = -1;
	info->philo.file_name = NULL;
	info->pid = NULL;
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
		return (free_vars(info));
	info->time_think = -1;
	if (info->num_philo % 2 == 1)
		if (info->time_sleep <= info->time_eat + info->time_eat / 4)
			info->time_think = info->time_eat - info->time_sleep + \
													info->time_eat / 4;
	info->philo.count_eat = 0;
	info->pid = (int *)malloc(sizeof(int) * \
					(info->num_philo + (info->num_eat != -1)));
	if (info->pid == NULL)
		return (free_vars(info));
	i = -1;
	while (++i < info->num_philo + (info->num_eat != -1))
		info->pid[i] = 0;
	info->philo.file_name = ft_strdup("for_eat_");
	if (info->philo.file_name == NULL)
		return (free_vars(info));
	return (0);
}

static int	init_sem(t_info *info)
{
	info->for_print = sem_open("for_print", O_CREAT, 0777, 1);
	if (info->for_print == (void *) -1)
		return (free_vars(info));
	sem_unlink("for_print");
	info->for_count = sem_open("for_count", O_CREAT, 0777, 0);
	if (info->for_count == (void *) -1)
	{
		sem_close(info->for_print);
		return (free_vars(info));
	}
	sem_unlink("for_count");
	info->fork = sem_open("fork", O_CREAT, 0777, info->num_philo);
	if (info->fork == (void *) -1)
	{
		sem_close(info->for_print);
		sem_close(info->for_count);
		return (free_vars(info));
	}
	sem_unlink("fork");
	return (0);
}

int	init_vars(int ac, char **av, t_info	**info)
{
	if (ac < 5 || ac > 6)
		return (-1);
	*info = (t_info *)malloc(sizeof(t_info));
	if (*info == NULL)
		return (-1);
	if (init_info(ac, av, *info) == -1)
		return (-1);
	if (init_sem(*info) == -1)
		return (-1);
	return (0);
}
