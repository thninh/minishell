/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:38:30 by cprouveu          #+#    #+#             */
/*   Updated: 2017/02/15 21:06:51 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *str, char c)
{
	int count_str;
	int count_words;

	count_str = 0;
	count_words = 0;
	while (str[count_str])
	{
		if (str[count_str] != c && (count_str == 0 || str[count_str - 1] == c))
		{
			count_words++;
		}
		count_str++;
	}
	return (count_words);
}

static int	ft_lenwords(char const *str, char c)
{
	int count;

	count = 0;
	while (str[count] && str[count] != c)
	{
		count++;
	}
	return (count);
}

static char	*ft_copystr(char const *str, char c)
{
	int		count;
	char	*str2;

	count = 0;
	str2 = NULL;
	str2 = (char *)malloc(sizeof(str2) * (ft_lenwords(str, c)) + 1);
	if (str2)
	{
		while (str[count] && str[count] != c)
		{
			str2[count] = str[count];
			count++;
		}
		str2[count] = '\0';
	}
	return (str2);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count_s;
	char	**str;
	int		count_str;

	str = NULL;
	count_s = 0;
	count_str = 0;
	if (!(s))
		return (str);
	str = (char **)malloc(sizeof(str) * (ft_nbwords(s, c) + 1));
	if (str)
	{
		while (s[count_s])
		{
			if (s[count_s] != c && (count_s == 0 || s[count_s - 1] == c))
			{
				str[count_str] = ft_copystr(s + count_s, c);
				count_str++;
			}
			count_s++;
		}
		str[count_str] = NULL;
	}
	return (str);
}
