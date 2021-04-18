/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:03:14 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/23 21:25:43 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' ||
		c == '\f' ||
		c == '\n' ||
		c == '\r' ||
		c == '\t' ||
		c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr++ - '0') * sign;
		if (INT_MAX < result)
			return (-1);
		else if (result < INT_MIN)
			return (0);
	}
	return ((int)result);
}
