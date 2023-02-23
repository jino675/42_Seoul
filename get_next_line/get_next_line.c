/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:41:39 by jiryu             #+#    #+#             */
/*   Updated: 2023/02/23 23:55:30 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	sub_get_index(const char *s, int idx, int mode)
{
	if (mode == 0)
	{
		while (idx < BUFFER_SIZE)
		{
			if (s[idx] != '\0')
				return (idx);
			++idx;
		}
	}
	else if (mode == 1)
	{
		while (idx < BUFFER_SIZE)
		{
			if (s[idx] == '\n')
				return (idx);
			else if (s[idx] == '\0')
				return (idx - 1);
			++idx;
		}
	}
	return (idx);
}

static int	process_buffer(char *buf, char **res_adr)
{
	int	start;
	int	end;

	start = sub_get_index(buf, 0, 0);
	if (start == BUFFER_SIZE)
		return (3);
	end = sub_get_index(buf, start, 1);
	if (end != BUFFER_SIZE)
	{
		if (sub_strjoin(res_adr, &buf[start], end - start + 1) == -1)
			return (-1);
		sub_memset(&buf[start], 0, end - start + 1);
		return (1);
	}
	else
	{
		if (sub_strjoin(res_adr, &buf[start], end - start) == -1)
			return (-1);
		sub_memset(&buf[start], 0, end - start);
		return (2);
	}
}

static void	sub_free(char **buffer_adr, char **res_adr, int flag)
{
	if (flag == -1 && *res_adr != NULL)
	{
		free(*res_adr);
		*res_adr = NULL;
	}
	if (*buffer_adr != NULL)
	{	
		free(*buffer_adr);
		*buffer_adr = NULL;
	}
}

static char	*sub_gnl(int fd, char **buffer_adr, char **res_adr)
{
	ssize_t	count;
	int		flag;

	count = read(fd, *buffer_adr, BUFFER_SIZE);
	while (count > 0)
	{
		flag = process_buffer(*buffer_adr, res_adr);
		if (flag != 2)
			break ;
		count = read(fd, *buffer_adr, BUFFER_SIZE);
	}
	if (count < 0)
		flag = -1;
	if (count == 0 || flag == -1)
		sub_free(buffer_adr, res_adr, flag);
	return (*res_adr);
}

char	*get_next_line(int fd)
{
	static char	*buffers[256];
	char		*res;
	int			flag;

	res = NULL;
	if (fd > 256 || fd < 0)
		return (NULL);
	if (buffers[fd] != NULL)
	{
		flag = process_buffer(buffers[fd], &res);
		if (flag == 1 || flag == -1)
		{
			if (flag == -1)
				sub_free(&buffers[fd], &res, flag);
			return (res);
		}
	}
	else
	{
		buffers[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (buffers[fd] == NULL)
			return (NULL);
		sub_memset(buffers[fd], 0, BUFFER_SIZE);
	}
	return (sub_gnl(fd, &buffers[fd], &res));
}

// #include<fcntl.h>
// #include<stdio.h>
// #include<time.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	clock_t start, end;
// 	start = clock();
// 	char *line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s",line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	end = clock();
// 	double res = (double)(end - start)/CLOCKS_PER_SEC;
// 	printf("\ntime:%f\n", res);
// }