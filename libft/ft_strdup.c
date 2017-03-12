/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:12:51 by cprouveu          #+#    #+#             */
/*   Updated: 2017/02/17 19:00:51 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	int		len;
	char	*dst;
	int		i;

	i = 0;
	dst = NULL;
	len = ft_strlen(s1);
	dst = (char*)malloc(sizeof(char) * len + 1);
	if (dst)
	{
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
