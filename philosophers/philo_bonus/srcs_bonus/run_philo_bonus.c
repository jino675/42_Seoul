/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/04 19:56:58 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

void	in_process(t_info *info, t_philo *philo, sem_t *fork);

static void	for_error(t_info *info)
{
	int		i;
	int		statloc;

	sem_wait(info->for_print);
	printf("something is wrong!\n");
	i = -1;
	while (++i < info->num_philo + (info->num_eat != -1))
	{
		kill(info->pid[i], SIGINT);
		waitpid(info->pid[i], &statloc, 0);
	}
	free_vars(info);
	exit(1);
}

static void	sub_run_philo_1(t_info *info, t_philo *philo)
{
	int		i;

	gettimeofday(&(info->start_time), NULL);
	philo->last_eat = info->start_time;
	i = -1;
	while (++i < info->num_philo)
		printf("%10dms \033[0;34m%3d is thinking\033[0m\n", 0, i);
	i = -1;
	while (++i < info->num_philo / 2)
	{
		info->pid[i * 2] = fork();
		if (info->pid[i * 2] < 0)
			for_error(info);
		if (info->pid[i * 2] == 0)
		{
			philo->number = i * 2;
			in_process(info, philo, info->fork);
		}
	}
	if (info->num_philo > 1)
		my_usleep(NULL, NULL, info->time_eat / 4);
}

static void	sub_run_philo_2(t_info *info, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < info->num_philo / 2)
	{
		info->pid[i * 2 + 1] = fork();
		if (info->pid[i * 2 + 1] < 0)
			for_error(info);
		if (info->pid[i * 2 + 1] == 0)
		{
			philo->number = i * 2 + 1;
			in_process(info, philo, info->fork);
		}
	}
	if (info->num_philo % 2 == 1)
	{
		info->pid[info->num_philo - 1] = fork();
		if (info->pid[info->num_philo - 1] < 0)
			for_error(info);
		if (info->pid[info->num_philo - 1] == 0)
		{
			philo->number = info->num_philo - 1;
			in_process(info, philo, info->fork);
		}
	}
}

static void	check_completed(t_info *info)
{
	int	i;

	info->pid[info->num_philo] = fork();
	if (info->pid[info->num_philo] < 0)
		for_error(info);
	if (info->pid[info->num_philo] == 0)
	{
		i = -1;
		while (++i < info->num_philo)
			sem_wait(info->for_count);
		sem_wait(info->for_print);
		printf("\n******** simulation is completed ********\n\n");
		exit(0);
	}
}

int	run_philo(t_info *info, t_philo *philo)
{
	int		i;
	int		statloc;

	sub_run_philo_1(info, philo);
	sub_run_philo_2(info, philo);
	if (info->num_eat != -1)
		check_completed(info);
	waitpid(0, &statloc, 0);
	i = -1;
	while (++i < info->num_philo + (info->num_eat != -1))
	{
		kill(info->pid[i], SIGINT);
		waitpid(info->pid[i], &statloc, 0);
	}
	sem_close(info->fork);
	sem_close(info->for_print);
	sem_close(info->for_count);
	return (0);
}
