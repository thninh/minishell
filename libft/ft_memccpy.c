/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:17:43 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:24:51 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*str_dst;
	char	*str_src;
	size_t	i;

	i = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	while (i < n && str_src[i] != c)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	str_dst[i] = str_src[i];
	return (dst + i + 1);
}
