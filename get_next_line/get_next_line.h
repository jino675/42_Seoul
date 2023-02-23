/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:37:24 by jiryu             #+#    #+#             */
/*   Updated: 2023/02/23 23:57:44 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	sub_strlen(const char *s);
void	sub_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	sub_strlcat(char *dst, const char *src, int len2, size_t dstsize);
void	*sub_memset(void *b, int c, size_t len);
int		sub_strjoin(char **res, char const *s2, int len2);
char	*get_next_line(int fd);

#endif
