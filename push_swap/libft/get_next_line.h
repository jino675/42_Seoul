/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:37:24 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 14:15:39 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	int				fd;
	char			*buffer;
	int				start;
	int				end;
	struct s_gnl	*next;
}	t_gnl;

size_t	sub_strlen(const char *s);
void	sub_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	sub_strlcat(char *dst, const char *src, int len2, size_t dstsize);
int		sub_strjoin(char **res, t_gnl *cur, size_t len2);
void	sub_free(t_gnl **buffers_adr, t_gnl *cur, char **res_adr, int flag);
char	*get_next_line(int fd);

#endif
