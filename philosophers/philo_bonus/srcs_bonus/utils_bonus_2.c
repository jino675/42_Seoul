/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:52:39 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/08 18:09:14 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/philo_bonus.h"

ssize_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (dstsize + src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*res;

	size = ft_strlen(s1) + 1;
	res = (char *)malloc(sizeof(char) * size);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, size);
	return (res);
}

int	ft_strattach(char **s1_adr, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	size;
	char	*temp;

	if (*s1_adr != NULL)
		len1 = ft_strlen(*s1_adr);
	else
		len1 = 0;
	len2 = ft_strlen(s2);
	size = len1 + len2 + 1;
	temp = (char *)malloc(sizeof(char) * size);
	if (temp == NULL)
		return (-1);
	if (*s1_adr != NULL)
	{
		ft_strlcpy(temp, *s1_adr, len1 + 1);
		ft_strlcat(temp, s2, size);
		free(*s1_adr);
	}
	else
		ft_strlcpy(temp, s2, size);
	*s1_adr = temp;
	return (0);
}
