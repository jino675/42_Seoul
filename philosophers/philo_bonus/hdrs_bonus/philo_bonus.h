/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:27:48 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/08 17:54:43 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# define SLEEP_UNIT 200

typedef struct s_philo
{
	int				number;
	int				count_eat;
	pthread_t		thread;
	sem_t			*for_eat;
	char			*file_name;
	struct timeval	last_eat;
}	t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				num_eat;
	int				*pid;
	sem_t			*fork;
	sem_t			*for_print;
	sem_t			*for_count;
	struct timeval	start_time;
	t_philo			philo;
}	t_info;

size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
ssize_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strattach(char **s1_adr, char const *s2);
char	*ft_itoa(int n);
int		free_vars(t_info *info);
long	get_diftime(struct timeval ref_time, t_philo *philo);
void	my_usleep(long time);

#endif
