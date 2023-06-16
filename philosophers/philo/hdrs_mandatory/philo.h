/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:27:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/06/16 21:22:11 by jiryu            ###   ########.fr       */
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
	struct timeval	start_time;
}	t_info;

typedef struct s_fork
{
	int				is_using;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	t_info			*info;
	t_fork			*fork;
	int				number;
	pthread_t		thread;
	struct timeval	last_eat;
	struct timeval	last_sleep;
}	t_philo;


size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);

#endif