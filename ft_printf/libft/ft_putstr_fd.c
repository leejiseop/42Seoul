/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:11:03 by jiselee           #+#    #+#             */
/*   Updated: 2021/03/28 23:48:48 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putstr_fd(char *s, int fd)
{
	int nbytes;

	if (fd < 0 || !s)
		return (0);
	nbytes = write(fd, s, ft_strlen(s));
	return (nbytes);
}
