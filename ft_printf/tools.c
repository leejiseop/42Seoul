/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:12:17 by ljs               #+#    #+#             */
/*   Updated: 2021/04/02 13:48:50 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		convert_to_large_hex(char *s)
{
	while (*s)
	{
		if (ft_isalpha(*s) && 'a' <= *s)
			*s -= 32;
		s++;
	}
}

char		*make_zero_arr(int len)
{
	char	*zero_arr;

	if (!(zero_arr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	zero_arr[len--] = '\0';
	while (0 <= len)
		zero_arr[len--] = '0';
	return (zero_arr);
}

void		attach_minus_0x(t_flags *flags, char **last, char *temp)
{
	if (flags->sign == -1)
		*last = ft_strjoin("-", temp, 0);
	if (flags->spec == 'p')
		*last = ft_strjoin("0x", temp, 0);
	if (flags->sign != -1 && flags->spec != 'p')
		*last = temp;
}

int			print_s_z(t_flags *flags, int s_z_length)
{
	int		nbytes;
	char	c;

	if (s_z_length <= 0)
		return (0);
	nbytes = 0;
	if (flags->zero == 1)
		c = '0';
	else
		c = ' ';
	while (0 < s_z_length--)
		nbytes += write(1, &c, 1);
	return (nbytes);
}
