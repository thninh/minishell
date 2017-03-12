/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:49:26 by cprouveu          #+#    #+#             */
/*   Updated: 2017/02/04 11:44:31 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_params(int ac, char **av)
{
	t_list	*tmp;
	t_list	*list;
	int		i;

	i = 2;
	tmp = NULL;
	list = ft_create_elem(av[1]);
	while (i < ac)
	{
		tmp = ft_create_elem(av[i]);
		tmp->next = list;
		list = tmp;
		i++;
	}
	return (list);
}
