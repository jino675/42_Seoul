/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:27:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/05 17:48:13 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# define SLEEP_UNIT 200

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				is_end;
	int				*count_eat;
	int				count;
	pthread_mutex_t	for_print;
	pthread_mutex_t	for_count;
	struct timeval	start_time;
}	t_info;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				number;
	int				is_using;
}	t_fork;

typedef struct s_philo
{
	t_info			*info;
	t_fork			*fork;
	int				number;
	int				idx_1;
	int				idx_2;
	pthread_t		thread;
	struct timeval	last_eat;
}	t_philo;

size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
int		free_vars(t_info *info, t_philo *philo, t_fork *fork);
long	get_diftime(struct timeval ref_time, t_philo *philo);
int		my_usleep(t_info *info, t_philo *philo, long time);
int		check_died(t_info *info, t_philo *philo);

#endif

	// int				*list;