/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:42:22 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:37:17 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*big && ft_strlen(little) == 0)
	{
		return ((char *)big);
	}
	if (len < (size_t)ft_strlen(little))
	{
		return (NULL);
	}
	while (big[i])
	{
		j = 0;
		while (little[j] && big[i + j] && big[i + j]
		== little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0' || j == len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
