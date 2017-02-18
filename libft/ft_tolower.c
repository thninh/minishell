/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:17:58 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 22:41:52 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char ctmp;

	if ((c <= 'Z') && (c >= 'A'))
	{
		ctmp = (unsigned char)c;
		return (ctmp + 32);
	}
	return (c);
}
