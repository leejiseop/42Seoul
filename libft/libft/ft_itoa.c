/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:53:23 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/29 16:22:12 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static size_t	get_int_length(int n)
{
	size_t	length;

	length = 1;
	while (n <= -10 || 10 <= n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void		less_than_zero(long long int *num, char *str, size_t *length_n)
{
	*num *= -1;
	*str = '-';
	*length_n -= 1;
	return ;
}

char			*ft_itoa(int n)
{
	size_t			length_n;
	long long int	num;
	char			*str;

	length_n = get_int_length(n);
	if (n < 0)
		length_n++;
	if (!(str = (char *)malloc(sizeof(char) * length_n + 1)))
		return (NULL);
	if ((num = (long long int)n) < 0)
		less_than_zero(&num, str++, &length_n);
	str[length_n--] = '\0';
	if (num == 0)
		*str = '0';
	while (num != 0)
	{
		*(str + length_n--) = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		return (--str);
	return (str);
}
