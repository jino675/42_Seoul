/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:36:52 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/13 17:14:19 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

int	with_fork(t_info *info, t_philo *philo, sem_t *fork);

static void	philo_sleep(t_info *info, t_philo *philo)
{
	long	dif_time;

	sem_wait(info->for_print);
	dif_time = get_diftime(info->start_time, NULL);
	printf("%10ldms \033[0;93m%3d is sleeping\033[0m\n", dif_time, philo->number);
	sem_post(info->for_print);
	my_usleep(info->time_sleep);
}

static void	philo_think(t_info *info, t_philo *philo)
{
	long	dif_time;

	sem_wait(info->for_print);
	dif_time = get_diftime(info->start_time, NULL);
	printf("%10ldms \033[0;36m%3d is thinking\033[0m\n", dif_time, philo->number);
	sem_post(info->for_print);
	if (info->time_think != -1)
		my_usleep(info->time_think);
}

static void	*check_died(void *var)
{
	t_info	*info;
	t_philo	*philo;
	long	dif_time;

	info = (t_info *)var;
	philo = &info->philo;
	while (1)
	{
		sem_wait(philo->for_eat);
		dif_time = get_diftime(philo->last_eat, NULL);
		if (dif_time >= (long)info->time_die)
		{
			sem_wait(info->for_print);
			dif_time = get_diftime(info->start_time, NULL);
			printf("%10ldms \033[0;31m%3d died\033[0m\n", dif_time, philo->number);
			free_vars(info);
			exit(0);
		}
		sem_post(philo->for_eat);
		usleep(SLEEP_UNIT);
	}
	return (NULL);
}

static void	for_error(t_info *info, char *temp)
{
	sem_wait(info->for_print);
	printf("something is wrong!\n");
	free_vars(info);
	if (temp != NULL)
		free(temp);
	exit(1);
}

void	in_process(t_info *info, t_philo *philo, sem_t *fork)
{
	char	*temp;

	if (info->num_philo > 1 && philo->number % 2 == 1)
		my_usleep(info->time_eat / 4);
	else if (info->num_philo > 1 && philo->number == info->num_philo - 1)
		my_usleep(info->time_eat + info->time_eat / 4);
	temp = ft_itoa(philo->number);
	if (temp == NULL)
		for_error(info, NULL);
	if (ft_strattach(&philo->file_name, temp) == -1)
		for_error(info, temp);
	free(temp);
	philo->for_eat = sem_open(philo->file_name, O_CREAT | O_EXCL, 0777, 1);
	if (philo->for_eat == (void *) -1)
		for_error(info, NULL);
	sem_unlink(philo->file_name);
	if (pthread_create(&philo->thread, NULL, check_died, (void *)info) != 0)
		for_error(info, NULL);
	while (1)
	{
		with_fork(info, philo, fork);
		philo_sleep(info, philo);
		philo_think(info, philo);
	}
}
