/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_multi_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:55:41 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/21 11:08:31 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split_str_multi_char(char *str, char *separators,
			int quotes_mode)
{
  int		i;
  int		count;
  int		start;
  char		**arr;
  int		quotes;

  i = 0;
  arr = NULL;
  count = 0;
  quotes = 0;
  while (str[i] != '\0')
    {
      if (!ft_find_c_in_str(str[i], separators))
	{
	  if ((i == 0 || ft_find_c_in_str(str[i - 1], separators)) && !quotes)
	    start = i;
	  if ((str[i] == '\'' || str[i] == '"') && quotes_mode)
	    quotes = !quotes;
	  count = count + 1;
	}
      else if (quotes)
	count = count + 1;
      else if (!quotes && count > 0 && (arr = ft_add_word_to_tab(str + start, count, arr)) != NULL)
	count = 0;
      i = i + 1;
    }
  if (count > 0)
    arr = ft_add_word_to_tab(str + start, count, arr);
  return (arr);
}
