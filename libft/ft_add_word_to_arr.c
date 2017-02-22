/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_word_to_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:11:03 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/21 11:15:29 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_add_word_to_arr(char *str, char **arr)
{
  char		**new_arr;

  if (arr == NULL)
    {
      new_arr = (char**)malloc(sizeof(char*) * 2);
      if (new_arr == NULL)
	return (arr);
      new_arr[0] = str;
      new_arr[1] = NULL;
    }
  else
    return (ft_malloc_new_arr(str, arr));
  return (new_arr);
}
