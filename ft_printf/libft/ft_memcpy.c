/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:43:13 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/21 21:20:53 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t count;

	if (!dest && !src)
		return (0);
	count = 0;
	while (count < n)
	{
		((unsigned char*)dest)[count] = ((unsigned char*)src)[count];
		count++;
	}
	return (dest);
}
