/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:52:23 by jiselee           #+#    #+#             */
/*   Updated: 2020/11/06 17:21:20 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	size_t	len_s_start;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	len_s_start = ft_strlen(s + start);
	if (len_s_start < len)
		len = len_s_start;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (0 < len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
