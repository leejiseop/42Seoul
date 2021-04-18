/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:14:03 by ljs               #+#    #+#             */
/*   Updated: 2021/04/02 13:47:54 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			prec;
	int			width;
	char		spec;
	int			base;
	int			sign;
	int			n_len;
	int			z_len;
}				t_flags;

int				ft_printf(const char *format, ...);
int				handle_format(char *format, int i, va_list ap);
int				print_spec(va_list ap, t_flags *flags);
void			init_flags(t_flags *flags);
void			fill_flags(char *format, int i, va_list ap, t_flags *flags);
void			fill_width_prec_star(va_list ap, t_flags *flags);
int				print_string(char *string, t_flags *flags);
int				print_s_z(t_flags *flags, int s_z_length);
int				print_char(va_list ap, t_flags *flags);
int				put_width(t_flags *flags, int word_length);
int				print_num(unsigned long long num, t_flags *flags);
int				print_non_zero(char *n_s, t_flags *flags);
int				print_zero(char *n_s, t_flags *flags);
char			*make_zero_arr(int len);
void			convert_to_large_hex(char *s);
void			attach_minus_0x(t_flags *flags, char **last, char *temp);

#endif
