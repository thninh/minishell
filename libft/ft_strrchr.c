/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:14:41 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:38:04 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			tmp = ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		tmp = ((char *)s + i);
	}
	return (tmp);
}
