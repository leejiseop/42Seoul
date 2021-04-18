/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:16:11 by ljs               #+#    #+#             */
/*   Updated: 2021/02/27 21:16:22 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
	{
		len++;
	}
	return (len);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length_src;

	length_src = ft_strlen(src);
	if (dstsize == 0)
		return (length_src);
	while (*src && 0 < --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (length_src);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_dst;
	size_t	length_src;
	int		copy_size;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (dstsize < length_dst)
		return (length_src + dstsize);
	copy_size = (int)(dstsize - length_dst - 1);
	while (*dst)
		dst++;
	while (0 < copy_size-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	if (dstsize < length_dst)
		return (length_src + dstsize);
	else
		return (length_src + length_dst);
}

char		*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length_str;
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	length_str = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (length_str + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
