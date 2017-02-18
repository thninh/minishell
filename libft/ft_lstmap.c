/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:00:05 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:50:43 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list_new;
	t_list	*tmp;
	int		size;

	list_new = NULL;
	size = 0;
	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		tmp = (*f)(lst);
		ft_lst_push_back(&list_new, ft_lstnew(tmp->content, tmp->content_size));
		if (size == ft_lstsize(list_new))
			return (NULL);
		else
			size = ft_lstsize(list_new);
		lst = lst->next;
	}
	return (list_new);
}
