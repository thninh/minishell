/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:55:15 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:50:05 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (content)
	{
		tmp->content_size = content_size;
		tmp->content = ft_memalloc(content_size);
		ft_memcpy(tmp->content, (void *)content, content_size);
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	tmp->next = NULL;
	return (tmp);
}
