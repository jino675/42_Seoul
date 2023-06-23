/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:27:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/22 22:39:19 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				is_died;
	int				is_completed;
	int				*count_eat;
	struct timeval	start_time;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_mutex_t	*fork;
	int				number;
	pthread_t		thread;
	struct timeval	last_eat;
}	t_philo;


size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);

#endif