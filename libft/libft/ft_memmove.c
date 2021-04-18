/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:56:08 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/21 16:24:32 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *uc_dest;
	unsigned char *uc_src;

	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	if (uc_dest < uc_src)
		while (0 < n--)
			*(uc_dest++) = *(uc_src++);
	if (uc_src < uc_dest)
		while (0 < n--)
			*(uc_dest + n) = *(uc_src + n);
	return (dest);
}
