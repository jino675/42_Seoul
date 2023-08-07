/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:31:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/08 17:27:16 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

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

int	free_vars(t_info *info)
{
	if (info != NULL)
	{
		if (info->pid != NULL)
			free(info->pid);
		if (info->philo.file_name != NULL)
			free(info->philo.file_name);
		free(info);
	}
	return (-1);
}

long	get_diftime(struct timeval ref_time, t_philo *philo)
{
	struct timeval	cur_time;
	long			dif_time;

	gettimeofday(&cur_time, NULL);
	if (philo != NULL)
	{
		sem_wait(philo->for_eat);
		philo->last_eat = cur_time;
		sem_post(philo->for_eat);
	}
	dif_time = (cur_time.tv_sec - ref_time.tv_sec) * 1000 \
			+ ((long)cur_time.tv_usec - (long)ref_time.tv_usec) / 1000;
	return (dif_time);
}

void	my_usleep(long time)
{
	struct timeval	start_time;
	long			dif_time;
	long			remain;

	remain = time / 2;
	gettimeofday(&start_time, NULL);
	while (1)
	{
		usleep(remain * 1000);
		dif_time = get_diftime(start_time, NULL);
		if (dif_time >= time)
			return ;
		remain = (time - dif_time) / 2;
	}
}
