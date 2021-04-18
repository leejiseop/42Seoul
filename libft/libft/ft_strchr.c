/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 03:18:53 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/22 16:57:55 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == (char)c)
		return (char *)(s);
	while (*s)
	{
		if (*s == (char)c)
			return (char *)(s);
		s++;
	}
	if (*s == (char)c)
		return (char *)(s);
	return (NULL);
}
