/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:36:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/06 21:23:19 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

static void	sub_here_doc(char *limiter, int fd)
{
	int		i;
	size_t	size_limiter;
	char	*cur_line;

	ft_printf("heredoc> ");
	size_limiter = ft_strlen(limiter);
	i = -1;
	while (1)
	{
		cur_line = get_next_line(0);
		if (ft_strlen(cur_line) == size_limiter + 1 && \
				ft_strncmp(cur_line, limiter, size_limiter) == 0)
			break ;
		write(fd, cur_line, ft_strlen(cur_line));
		ft_printf("heredoc> ");
	}
}

int	here_doc(t_etc *e, char *limiter)
{
	int		fd;

	if (access("/tmp/.pipex_here_doc", F_OK) == 0 && \
			(access("/tmp/.pipex_here_doc", W_OK) == -1 || \
				access("/tmp/.pipex_here_doc", R_OK) == -1))
		error_exit("/tmp/.pipex_here_doc", "Permission denied", e);
	fd = open("/tmp/.pipex_here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_exit("/tmp/here_doc", "open error!", e);
	sub_here_doc(limiter, fd);
	close(fd);
	fd = open("/tmp/.pipex_here_doc", O_RDONLY);
	if (fd == -1)
		error_exit("/tmp/here_doc", "open error!", e);
	return (fd);
}
