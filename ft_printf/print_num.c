/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:11:42 by ljs               #+#    #+#             */
/*   Updated: 2021/04/02 02:11:43 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_zero(char *n_s, t_flags *flags)
{
	int		nbytes;
	int		num_len;

	nbytes = 0;
	num_len = ft_strlen(n_s);
	if (flags->sign == -1 && flags->width <= num_len)
		flags->width = num_len + 1;
	if (flags->sign == 1 && flags->width < num_len)
		flags->width = num_len;
	if (flags->sign == -1)
	{
		nbytes += write(1, "-", 1);
		flags->width--;
	}
	nbytes += print_s_z(flags, (flags->width - num_len));
	nbytes += write(1, n_s, num_len);
	return (nbytes);
}

int			print_non_zero(char *n_s, t_flags *flags)
{
	int		nbytes;
	char	*zero_arr;
	int		s_z_len;
	char	*temp;
	char	*last;

	nbytes = 0;
	if (flags->prec < (int)ft_strlen(n_s))
		flags->prec = ft_strlen(n_s);
	zero_arr = make_zero_arr(flags->prec - ft_strlen(n_s));
	temp = ft_strjoin(zero_arr, n_s, 0);
	attach_minus_0x(flags, &last, temp);
	if (flags->width < (int)ft_strlen(last))
		flags->width = (int)ft_strlen(last);
	s_z_len = flags->width - (int)ft_strlen(last);
	if (flags->minus == 1)
		nbytes += write(1, last, (int)ft_strlen(last));
	nbytes += print_s_z(flags, s_z_len);
	if (flags->minus == 0)
		nbytes += write(1, last, (int)ft_strlen(last));
	free(zero_arr);
	free(temp);
	if (flags->sign == -1 || flags->spec == 'p')
		free(last);
	return (nbytes);
}

int			print_num(unsigned long long num, t_flags *flags)
{
	int		nbytes;
	char	*num_str;

	nbytes = 0;
	if (ft_strchr("pxX", flags->spec))
		flags->base = 16;
	if ((flags->spec == 'd' || flags->spec == 'i') && (int)num < 0)
	{
		flags->sign = -1;
		num *= -1;
	}
	num_str = ft_itoa_base(num, flags->base, flags->prec);
	if (flags->spec == 'X')
		convert_to_large_hex(num_str);
	if (flags->zero == 1)
		nbytes += print_zero(num_str, flags);
	else
		nbytes += print_non_zero(num_str, flags);
	free(num_str);
	return (nbytes);
}
