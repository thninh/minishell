/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:13:09 by cprouveu          #+#    #+#             */
/*   Updated: 2017/03/11 12:14:11 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nchar(const char *s)
{
	int	count;

	count = 0;
	while (s[count] && (s[count] == ' ' ||
				s[count] == '\n' || s[count] == '\t'))
		count++;
	return (count);
}

static	int	ft_rnchar(const char *s)
{
	int	count;
	int	count_whitespaces;

	count = 0;
	count = ft_strlen(s) - 1;
	count_whitespaces = 0;
	while (s[count] && (s[count] == ' ' ||
				s[count] == '\n' || s[count] == '\t'))
	{
		count--;
		count_whitespaces++;
	}
	return (count_whitespaces);
}

char		*ft_strtrim(char const *s)
{
	int		count_s;
	int		count_str;
	char	*str;

	if (!s)
		return (NULL);
	count_s = 0;
	count_s = ft_nchar(s);
	count_str = 0;
	str = NULL;
	str = ft_strnew((int)ft_strlen(s) == ft_nchar(s) ? 1 : (int)ft_strlen(s) -
			ft_nchar(s) - ft_rnchar(s) + 1);
	if (str)
	{
		while (count_s < ((int)ft_strlen(s) - ft_rnchar(s)))
		{
			str[count_str] = s[count_s];
			count_s++;
			count_str++;
		}
		str[count_str] = '\0';
	}
	return (str);
}
