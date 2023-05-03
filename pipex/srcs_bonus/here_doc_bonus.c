/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:36:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/03 21:21:33 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/pipex_bonus.h"

int	here_doc(t_etc *e, char *limiter)
{
	int		i;
	int		fd;
	size_t	size_limiter;
	char	*cur_line;

	unlink("/tmp/.here_doc");
	fd = open("/tmp/.here_doc", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		error_exit("here_doc", "Something wrong!", e);
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
	close(fd);
	fd = open("/tmp/.here_doc", O_RDONLY);
	return (fd);
}
