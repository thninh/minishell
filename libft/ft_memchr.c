/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:20:26 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:25:41 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*(unsigned char *)(s + i)) != ((unsigned char)c))
	{
		i++;
	}
	if (i == n)
	{
		return (NULL);
	}
	return ((void *)(s + i));
}
