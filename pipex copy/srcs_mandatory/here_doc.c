/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:58:10 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/11 18:09:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"

static void	error_exit(char const *msg_1, char const *msg_2)
{
	write(2, "pipex: ", 7);
	if (msg_1 != NULL)
	{
		write(2, msg_1, ft_strlen(msg_1));
		write(2, ": ", 2);
	}
	if (msg_2 != NULL)
		write(2, msg_2, ft_strlen(msg_2));
	write(2, "\n", 1);
	exit(127);
}

int	main(int ac, char **av)
{
	int		i;
	size_t	size_limiter;
	char	*cur_line;

	ft_printf("heredoc> ");
	size_limiter = ft_strlen(av[1]);
	i = -1;
	while (1)
	{
		cur_line = get_next_line(0);
		if (ft_strlen(cur_line) == size_limiter + 1 && \
				ft_strncmp(cur_line, av[1], size_limiter) == 0)
			break ;
		if (write(3, cur_line, ft_strlen(cur_line)) == -1)
			error_exit("here_doc", "write error!");
		ft_printf("heredoc> ");
	}
}
