/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:13:03 by jiselee           #+#    #+#             */
/*   Updated: 2020/11/06 21:26:28 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**allocation_fail(char **array, int malloc_length)
{
	int		i;

	i = 0;
	while (i < malloc_length)
		free(array[i++]);
	free(array);
	return (NULL);
}

static int	get_str_num(char const *s, char c)
{
	int		str_num;
	int		i;

	str_num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			str_num++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (str_num);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		str_num;
	int		s_i;
	int		a_i;
	int		copy;

	str_num = get_str_num(s, c);
	if (!s || !(array = (char **)malloc(sizeof(char *) * (str_num + 1))))
		return (NULL);
	s_i = 0;
	a_i = 0;
	while (a_i < str_num)
	{
		while (s[s_i] == c)
			s_i++;
		copy = s_i;
		while (s[s_i] && s[s_i] != c)
			s_i++;
		if (!(array[a_i] = (char *)malloc(sizeof(char) * (s_i - copy + 1))))
			return (allocation_fail(array, str_num + 1));
		ft_strlcpy(array[a_i], s + copy, s_i - copy + 1);
		a_i++;
	}
	array[a_i] = NULL;
	return (array);
}
