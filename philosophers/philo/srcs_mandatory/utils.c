/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:31:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/22 22:56:44 by jiryu            ###   ########.fr       */
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

void	free_vars(t_info *info, t_philo *philo, pthread_mutex_t *fork)
{
	if (info->count_eat != NULL)
		free(info->count_eat);
	if (fork != NULL)
		free(fork);
	if (philo != NULL)
		free(philo);
}