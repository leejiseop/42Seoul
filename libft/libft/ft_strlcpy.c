/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:43:11 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/23 16:29:35 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
