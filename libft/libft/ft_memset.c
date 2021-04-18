/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <jiselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:35:54 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/21 21:36:52 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uc_s;
	unsigned char	uc_c;

	uc_s = (unsigned char *)s;
	uc_c = (unsigned char)c;
	while (0 < n--)
		*uc_s++ = uc_c;
	return (s);
}
