/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:09:05 by jiryu             #+#    #+#             */
/*   Updated: 2023/02/19 17:53:00 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	sub_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	sub_strlcat(char *dst, const char *src, int len2, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = len2;
	if (dst == NULL && dstsize == 0)
		return (dstsize + src_len);
	dst_len = sub_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

void	sub_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize)
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0)
		dst[i] = '\0';
}

void	*sub_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	val;

	val = c;
	p = b;
	i = 0;
	while (i < len)
	{
		p[i] = val;
		++i;
	}
	return (b);
}

int	sub_strjoin(char **res, char const *s2, int len2)
{
	size_t	len1;
	size_t	size;
	char	*temp;

	if (*res != NULL)
		len1 = sub_strlen(*res);
	else
		len1 = 0;
	size = len1 + len2 + 1;
	temp = (char *)malloc(sizeof(char) * size);
	if (temp == NULL)
		return (-1);
	if (*res != NULL)
	{
		sub_strlcpy(temp, *res, len1 + 1);
		sub_strlcat(temp, s2, len2, size);
		free(*res);
	}
	else
		sub_strlcpy(temp, s2, size);
	*res = temp;
	return (0);
}
