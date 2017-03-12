/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:58:14 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/08 20:15:15 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *alst;
	if (!alst)
		return ;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_lstdelone(&tmp2, del);
	}
	ft_lstdelone(&tmp2, del);
	*alst = NULL;
}
