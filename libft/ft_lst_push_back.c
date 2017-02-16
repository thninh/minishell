/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:03:09 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 14:03:39 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin, t_list *list)
{
	t_list		*tmp;

	tmp = *begin;
	if (!tmp)
		*begin = list;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
	}
}
