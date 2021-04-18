/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiselee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:37:53 by jiselee           #+#    #+#             */
/*   Updated: 2020/10/30 18:13:32 by jiselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*start;

	if (!(start = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	start->content = content;
	start->next = NULL;
	return (start);
}
