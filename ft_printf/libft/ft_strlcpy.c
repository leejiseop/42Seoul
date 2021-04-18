/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:43:11 by jiselee           #+#    #+#             */
/*   Updated: 2021/04/02 02:08:01 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length_src;
	int		i;

	i = 0;
	length_src = ft_strlen(src);
	if (dstsize == 0)
		return (length_src);
	while (*src && 0 < --dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length_src);
}
