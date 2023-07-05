/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:27:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/04 19:58:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <semaphore.h>
# define SLEEP_UNIT 200

typedef struct s_philo
{
	int				number;
	int				count_eat;
	struct timeval	last_eat;
}	t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				is_end;
	int				*pid;
	sem_t			*fork;
	sem_t			*for_print;
	sem_t			*for_count;
	struct timeval	start_time;
	t_philo			philo;
}	t_info;

size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
int		free_vars(t_info *info);
long	get_diftime(struct timeval ref_time, t_philo *philo);
int		my_usleep(t_info *info, t_philo *philo, long time);
int		check_died(t_info *info, t_philo *philo);

#endif
