/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:31:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/13 18:50:09 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	size_t		i;
	long long	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '+')
		++i;
	if (str[i] == '\0')
		return (-1);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		++i;
		if (res > 2147483647)
			return (-1);
	}
	if (i < ft_strlen(str))
		return (-1);
	return ((int) res);
}

int	free_vars(t_info *info, t_philo *philo, t_fork *fork)
{
	if (info != NULL)
	{
		if (info->count_eat != NULL)
			free(info->count_eat);
		free(info);
	}
	if (fork != NULL)
		free(fork);
	if (philo != NULL)
		free(philo);
	return (-1);
}

long	get_diftime(struct timeval ref_time, t_philo *philo)
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

int	my_usleep(t_info *info, t_philo *philo, long time)
{
	struct timeval	start_time;
	long			dif_time;

	gettimeofday(&start_time, NULL);
	while (1)
	{
		usleep(SLEEP_UNIT);
		if (info != NULL && philo != NULL)
		{
			dif_time = get_diftime(philo->last_eat, NULL);
			if (dif_time >= (long)info->time_die)
				return (-1);
		}
		dif_time = get_diftime(start_time, NULL);
		if (dif_time >= time)
			return (0);
	}
}
