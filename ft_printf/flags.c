/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:10:48 by ljs               #+#    #+#             */
/*   Updated: 2021/04/02 02:11:32 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_width_prec_star(va_list ap, t_flags *flags)
{
	if (flags->prec == -1)
	{
		if ((flags->width = va_arg(ap, int)) < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	else
		flags->prec = va_arg(ap, int);
}

void		fill_flags(char *format, int i, va_list ap, t_flags *flags)
{
	if (format[i] == '-')
		flags->minus = 1;
	else if (format[i] == '0' && flags->width == 0 && flags->prec == -1)
		flags->zero = 1;
	else if (format[i] == '.')
		flags->prec = 0;
	else if (ft_isdigit(format[i]))
	{
		if (flags->prec == -1)
			flags->width = (flags->width * 10) + (format[i] - '0');
		else
			flags->prec = (flags->prec * 10) + (format[i] - '0');
	}
	else if (format[i] == '*')
		fill_width_prec_star(ap, flags);
}

void		init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->spec = '\0';
	flags->base = 10;
	flags->sign = 1;
	flags->n_len = 0;
	flags->z_len = 0;
}
