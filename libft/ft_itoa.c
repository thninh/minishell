/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:15:24 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:24:09 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nb(int n)
{
	int		len	;
	long	big_nb;

	big_nb = n;
	len = 0;
	if (n < 0)
	{
		big_nb = -n;
		len++;
	}
	while (big_nb != big_nb % 10)
	{
		len++;
		big_nb = (big_nb - big_nb % 10) / 10;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	fat_nb;

	i = 0;
	fat_nb = n;
	len = ft_len_nb(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	if (n < 0)
	{
		str[0] = '-';
		fat_nb *= -1;
	}
	while (i < (n < 0 ? len - 1 : len))
	{
		str[len - i - 1] = (fat_nb % 10) + 48;
		fat_nb = (fat_nb - fat_nb % 10) / 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}
