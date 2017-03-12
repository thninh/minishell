/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:33:29 by cprouveu          #+#    #+#             */
/*   Updated: 2017/03/11 13:51:42 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int sign;
	int i;
	int nb;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
	|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign = sign * (-1);
	}
	if ((str[i] == '+') || (str[i] == '-'))
	{
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
