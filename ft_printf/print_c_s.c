/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:10:27 by ljs               #+#    #+#             */
/*   Updated: 2021/04/02 13:48:30 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(va_list ap, t_flags *flags)
{
	int		nbytes;
	char	c;

	nbytes = 0;
	if (flags->spec == '%')
		c = '%';
	else
		c = (char)va_arg(ap, int);
	if (flags->minus == 1)
		nbytes += write(1, &c, 1);
	nbytes += print_s_z(flags, flags->width - 1);
	if (flags->minus == 0)
		nbytes += write(1, &c, 1);
	return (nbytes);
}

int			print_string(char *string, t_flags *flags)
{
	int		nbytes;
	int		length;
	int		s_z_length;

	if (string == NULL)
		string = "(null)";
	nbytes = 0;
	length = (int)ft_strlen(string);
	if (length < flags->prec || flags->prec <= -1)
		flags->prec = length;
	if (flags->width <= flags->prec)
		return (write(1, string, flags->prec));
	s_z_length = flags->width - flags->prec;
	if (flags->minus == 1)
		nbytes += write(1, string, flags->prec);
	nbytes += print_s_z(flags, s_z_length);
	if (flags->minus == 0)
		nbytes += write(1, string, flags->prec);
	return (nbytes);
}
