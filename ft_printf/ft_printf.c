/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:29:01 by ljs               #+#    #+#             */
/*   Updated: 2021/04/13 14:13:40 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_spec(va_list ap, t_flags *flags)
{
	int			nbytes;
	char		this;
	va_list		z;

	va_copy(z, ap);
	nbytes = 0;
	this = flags->spec;
	if (this == 'c' || this == '%')
		nbytes = print_char(ap, flags);
	else if (this == 's')
		nbytes = print_string(va_arg(ap, char *), flags);
	else if (this == 'd' || this == 'i')
		nbytes = print_num(va_arg(ap, int), flags);
	else if (this == 'u')
		nbytes = print_num(va_arg(ap, unsigned int), flags);
	else if (this == 'p')
		nbytes += print_num(va_arg(ap, unsigned long long), flags);
	else if (this == 'x' || this == 'X')
		nbytes = print_num(va_arg(ap, unsigned int), flags);
	return (nbytes);
}

int				handle_format(char *format, int i, va_list ap)
{
	int			nbytes;
	t_flags		*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	init_flags(flags);
	while (ft_strchr("csdiupxX%", format[i]) == NULL && format[i])
		fill_flags(format, i++, ap, flags);
	if (flags->minus == 1 || -1 < flags->prec)
		flags->zero = 0; // 좌측정렬이거나 정밀도가 뭐라도 들어오면 제로플래그 없앰
	flags->spec = format[i++];
	nbytes = print_spec(ap, flags);
	free(flags);
	return (nbytes);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			nbytes;
	va_list		ap;

	i = 0;
	nbytes = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			nbytes += handle_format((char *)format, ++i, ap);
			while (ft_strchr("csdiupxX%", format[i]) == NULL && format[i])
				i++;
		}
		else
			nbytes += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (nbytes);
}
