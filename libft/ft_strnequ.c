/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:40:58 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 13:41:23 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strnequ(const char *s1, const char *s2, int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[count] && s2[count] && s1[count] == s2[count] && count < n)
		count++;
	if (count != n && s1[count] != s2[count])
		return (0);
	else
		return (1);
}
