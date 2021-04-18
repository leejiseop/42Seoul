/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:50:39 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/22 16:01:36 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *find;

	find = NULL;
	if (*s == (char)c)
		find = s;
	while (*s)
	{
		if (*s == (char)c)
			find = s;
		s++;
	}
	if (*s == (char)c)
		find = s;
	return (char *)(find);
}
