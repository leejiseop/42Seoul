/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:03:14 by jiselee           #+#    #+#             */
/*   Updated: 2021/03/25 02:26:29 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int			ft_atoi(const char *nptr)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr - '0') * sign;
		nptr++;
		if (INT_MAX < result)
			return (-1);
		else if (result < INT_MIN)
			return (0);
	}
	return ((int)result);
}
