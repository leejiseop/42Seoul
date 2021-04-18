/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 02:19:25 by ljs               #+#    #+#             */
/*   Updated: 2021/04/01 06:43:58 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_n_base_length(unsigned long long n, int base, int prec)
{
	int			length;

	length = 1;
	if (n == 0 && prec == 0)
		return (0);
	while ((unsigned int)base <= n)
	{
		n /= base;
		length++;
	}
	return (length);
}

char		*ft_itoa_base(unsigned long long num, int base, int prec)
{
	char		*str;
	char		*base_arr;
	int			length_str;

	base_arr = "0123456789abcdef";
	length_str = get_n_base_length(num, base, prec);
	if (!(str = (char *)malloc(sizeof(char) * length_str + 1)))
		return (NULL);
	str[length_str--] = '\0';
	if (num == 0 && prec == 0)
		return (str);
	if (num == 0 && prec != 0)
		str[length_str] = '0';
	while (0 < num)
	{
		str[length_str--] = base_arr[num % base];
		num /= base;
	}
	return (str);
}
