/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:33:42 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:33:32 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (!s)
	{
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tmp)
	{
		while (s[i])
		{
			tmp[i] = (*f)(s[i]);
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
