/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pipex_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:36:33 by jiryu             #+#    #+#             */
/*   Updated: 2023/05/11 18:00:35 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_mandatory/pipex.h"

// static void	sub_here_doc(t_etc *e, char *limiter, int fd)
// {
// 	int		i;
// 	size_t	size_limiter;
// 	char	*cur_line;

// 	ft_printf("heredoc> ");
// 	size_limiter = ft_strlen(limiter);
// 	i = -1;
// 	while (1)
// 	{
// 		cur_line = get_next_line(0);
// 		if (ft_strlen(cur_line) == size_limiter + 1 && \
// 				ft_strncmp(cur_line, limiter, size_limiter) == 0)
// 			break ;
// 		if (write(fd, cur_line, ft_strlen(cur_line)) == -1)
// 			error_exit(NULL, "write error!", e);
// 		ft_printf("heredoc> ");
// 	}
// }

// int	here_doc(t_etc *e, char *limiter)
// {
// 	int		fd;

// 	if (access("/tmp/.pipex_here_doc", F_OK) == 0 && \
// 			(access("/tmp/.pipex_here_doc", W_OK) == -1 || \
// 				access("/tmp/.pipex_here_doc", R_OK) == -1))
// 		error_exit("/tmp/.pipex_here_doc", "Permission denied", e);
// 	fd = open("/tmp/.pipex_here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		error_exit("/tmp/here_doc", "open error!", e);
// 	sub_here_doc(e, limiter, fd);
// 	close(fd);
// 	fd = open("/tmp/.pipex_here_doc", O_RDONLY);
// 	if (fd == -1)
// 		error_exit("/tmp/here_doc", "open error!", e);
// 	return (fd);
// }

static void	sub_sub_pipe_here_doc(t_etc *e, char **av, char **envp)
{
	char	**temp;

	close(e->fds[0][0]);
	if (dup2(e->fds[0][1], 3) == -1)
		error_exit(NULL, "dup2 error!", e);
	close(e->fds[0][1]);
	temp = (char **)malloc(sizeof(char *) * 3);
	if (temp == NULL)
		error_exit(NULL, "memory allocation error!", e);
	temp[0] = ft_strdup("./srcs_here_doc/here_doc");
	temp[1] = ft_strdup(av[2]);
	temp[2] = NULL;
	if (execve(temp[0], temp, envp) == -1)
	{
		close(0);
		close(1);
		error_exit(NULL, "execve error!", e);
	}
}

void	sub_pipe_here_doc(t_etc *e, char **av, char **envp)
{
	if (pipe(e->fds[0]) == -1)
		error_exit(NULL, "pipe error", e);
	e->pids[0] = fork();
	if (e->pids[0] < 0)
		error_exit(NULL, "fork error!", e);
	else if (e->pids[0] == 0)
		sub_sub_pipe_here_doc(e, av, envp);
	close(e->fds[0][1]);
}
