/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:54:18 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/29 16:54:09 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	trim_left(char const *s1, char const *set, size_t *left)
{
	size_t	set_index;

	set_index = 0;
	while (set[set_index])
	{
		if (s1[*left] == set[set_index])
		{
			(*left)++;
			set_index = 0;
		}
		else
			set_index++;
	}
}

static void	trim_right(char const *s1, char const *set, size_t *right)
{
	size_t	set_index;

	set_index = 0;
	while (set[set_index])
	{
		if (s1[*right] == set[set_index])
		{
			(*right)--;
			set_index = 0;
		}
		else
			set_index++;
	}
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(s1) - 1;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	trim_left(s1, set, &left);
	if (right <= left)
		return (ft_strdup(""));
	trim_right(s1, set, &right);
	if (right <= left)
		return (ft_strdup(""));
	if (!(str_trim = (char *)malloc(sizeof(char) * ((right - left + 1) + 1))))
		return (NULL);
	ft_strlcpy(str_trim, (s1 + left), (right - left + 1) + 1);
	return (str_trim);
}
