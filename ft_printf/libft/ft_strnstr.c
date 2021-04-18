/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:46:38 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/21 21:42:59 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	hay_len;
	size_t	search;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	hay_len = ft_strlen(haystack);
	if (len < needle_len || hay_len < needle_len)
		return (NULL);
	search = len < hay_len ? len : hay_len;
	while (needle_len <= search)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		search--;
	}
	return (NULL);
}
