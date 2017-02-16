/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:53:01 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/12 10:55:13 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = data;
		tmp->next = NULL;
	}
	return (tmp);
}
