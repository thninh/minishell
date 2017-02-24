/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_multi_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:55:41 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 19:02:44 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_str_multi_char4(char **arr, char *str, int start, int count)
{
	if (count > 0)
		arr = ft_add_word_to_tab(str + start, count, arr);
	return (arr);
}

int		ft_split_str_multi_char3(char *str, int i, int quotes_mode, int quotes)
{
	if ((str[i] == '\'' || str[i] == '"') && quotes_mode)
		quotes = !quotes;
	return (quotes);
}

int		ft_split_str_multi_char2(char *str, int i, char *separators, int quotes, int start)
{
	if ((i == 0 || ft_find_c_in_str(str[i - 1], separators)) && !quotes)
		start = i;
	return (start);
}

char	**ft_split_str_multi_char1(char **arr, char *str, char *separators,
			int quotes_mode)
{
	int		i;
	int		count;
	int		start;
	int		quotes;

	i = 0;
	count = 0;
	quotes = 0;
	while (str[i] != '\0')
	{
		if (!ft_find_c_in_str(str[i], separators))
		{
			start = ft_split_str_multi_char2(str, i, separators, quotes, start);
			quotes = ft_split_str_multi_char3(str, i, quotes_mode, quotes);
			count = count + 1;
		}
		else if (quotes)
			count = count + 1;
		else if (!quotes && count > 0 && (arr = ft_add_word_to_tab(str + start,
				count, arr)) != NULL)
			count = 0;
		i = i + 1;
	}
	arr = ft_split_str_multi_char4(arr, str, start, count);
	return (arr);
}

char	**ft_split_str_multi_char(char *str, char *separators,
			int quotes_mode)
{
	  char		**arr;

	  arr = NULL;
	arr = ft_split_str_multi_char1(arr, str, separators, quotes_mode);
	return (arr);
}
