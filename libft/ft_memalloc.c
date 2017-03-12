/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:16:50 by cprouveu          #+#    #+#             */
/*   Updated: 2017/02/25 11:09:12 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void*tmp;

	tmp = NULL;
	tmp = malloc(size);
	if (tmp)
	{
		ft_bzero(tmp, size);
	}
	return (tmp);
}
