/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_c_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:57:59 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/21 11:06:16 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_c_in_str(char c, char *separators)
{
  int		i;

  i = 0;
  while (c != separators[i] && separators[i] != '\0')
    i = i + 1;
  if (separators[i] != '\0')
    return (1);
  else
    return (0);
}
