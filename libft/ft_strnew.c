/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:36:55 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:36:25 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	count;
	char	*str;

	count = 0;
	str = NULL;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str)
	{
		while (count < size + 1)
		{
			str[count] = '\0';
			count++;
		}
	}
	return (str);
}
