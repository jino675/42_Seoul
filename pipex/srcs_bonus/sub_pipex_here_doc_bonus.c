/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pipex_here_doc_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:36:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/15 15:47:38 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	read_input(t_etc *e, char **av)
{
	int		i;
	size_t	size_limiter;
	char	*cur_line;
	char	*limiter;

	limiter = av[2];
	size_limiter = ft_strlen(limiter);
	ft_printf("heredoc> ");
	i = -1;
	while (1)
	{
		cur_line = get_next_line(0);
		if (cur_line == NULL)
			error_exit("heredoc", "gnl error!", e, 1);
		if (ft_strlen(cur_line) == size_limiter + 1 && \
				ft_strncmp(cur_line, limiter, size_limiter) == 0)
			break ;
		if (write(e->fd_in, cur_line, ft_strlen(cur_line)) == -1)
			error_exit(NULL, "write error!", e, 1);
		ft_printf("heredoc> ");
	}
}

static int	find_length(int i)
{
	int		k;

	k = 0;
	while (i > 0)
	{
		i /= 10;
		++k;
	}
	return (k);
}

static void	sub_check_temp_file(t_etc *e)
{
	int		i;
	int		cur_length;
	int		last_length;
	char	*temp_nbr;

	last_length = 1;
	i = 1;
	while (access(e->temp_file, F_OK) == 0 && access(e->temp_file, W_OK) == -1)
	{
		++i;
		temp_nbr = ft_itoa(i);
		if (temp_nbr == NULL)
			error_exit(NULL, "memory allocation error!", e, 139);
		cur_length = find_length(i);
		if (last_length < cur_length)
			if (ft_strattach(&e->temp_file, "*") == -1)
				error_exit(NULL, "memory allocation error!", e, 139);
		last_length = cur_length;
		while (--cur_length >= 0)
			e->temp_file[ft_strlen(e->temp_file) - 1 - cur_length] = \
							temp_nbr[ft_strlen(temp_nbr) - 1 - cur_length];
		free(temp_nbr);
	}
}

static void	check_temp_file(t_etc *e)
{
	e->temp_file = ft_strdup("/tmp/.pipex_here_doc_1");
	if (e->temp_file == NULL)
		error_exit(NULL, "memory allocation error!", e, 139);
	sub_check_temp_file(e);
	if (access(e->temp_file, F_OK) == 0 && access(e->temp_file, W_OK) == 0)
		unlink(e->temp_file);
}

void	sub_pipe_here_doc(t_etc *e, char **av)
{
	check_temp_file(e);
	e->fd_in = open(e->temp_file, O_WRONLY | O_CREAT, 0644);
	if (e->fd_in == -1)
		error_exit(e->temp_file, "open error!", e, 1);
	read_input(e, av);
	close(e->fd_in);
	e->fd_in = open(e->temp_file, O_RDONLY);
	if (e->fd_in == -1)
		error_exit(e->temp_file, "open error!", e, 1);
	unlink(e->temp_file);
}
