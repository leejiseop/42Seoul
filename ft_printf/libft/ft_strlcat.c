/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:41:42 by jiselee           #+#    #+#             */
/*   Updated: 2020/11/04 22:37:03 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
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
