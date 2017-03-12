/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:33:00 by cprouveu          #+#    #+#             */
/*   Updated: 2016/11/06 14:41:22 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char	const *s2)
{
	size_t	count_params;
	size_t	count_str;
	char	*str;

	count_params = 0;
	count_str = 0;
	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str)
	{
		while (count_params < ft_strlen(s1))
			str[count_str++] = s1[count_params++];
		count_params = 0;
		while (count_params < ft_strlen(s2))
			str[count_str++] = s2[count_params++];
		str[count_str] = '\0';
	}
	return (str);
}
