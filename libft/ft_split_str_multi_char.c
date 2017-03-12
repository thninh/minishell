/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_multi_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:55:41 by Geekette          #+#    #+#             */
/*   Updated: 2017/03/11 12:22:08 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_str_multi_char3(char **a, char *str, int s, int c)
{
	if (c > 0)
		a = ft_add_word_to_tab(str + s, c, a);
	return (a);
}

int		ft_split_str_multi_char2(char *str, int i, int q_mode, int q)
{
	if ((str[i] == '\'' || str[i] == '"') && q_mode)
		q = !q;
	return (q);
}

char	**ft_split_str_multi_char1(char **a, char *str, char *separators,
			int q_mode)
{
	int		i;
	int		c;
	int		s;
	int		q;

	i = 0;
	c = 0;
	q = 0;
	while (str[i] != '\0')
	{
		if (!ft_strchr(separators, str[i]))
		{
			if ((i == 0 || ft_strchr(separators, str[i - 1])) && !q)
				s = i;
			q = ft_split_str_multi_char2(str, i, q_mode, q);
			c = c + 1;
		}
		else if (q)
			c = c + 1;
		else if (!q && c > 0 && (a = ft_add_word_to_tab(str + s, c, a)) != NULL)
			c = 0;
		i = i + 1;
	}
	a = ft_split_str_multi_char3(a, str, s, c);
	return (a);
}

char	**ft_split_str_multi_char(char *str, char *separators,
			int q_mode)
{
	char	**a;

	a = NULL;
	a = ft_split_str_multi_char1(a, str, separators, q_mode);
	return (a);
}
