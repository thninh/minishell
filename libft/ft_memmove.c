/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:26:33 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 17:15:57 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n == 0)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	n--;
	while (n > 0)
	{
		((char *)dst)[n] = ((char *)src)[n];
		n--;
	}
	((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}
