/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:36:43 by cprouveu          #+#    #+#             */
/*   Updated: 2017/02/19 16:16:44 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
  int		result;
  size_t		i;

  if (n > 0)
    {
      result = 0;
      i = 0;
      while (i < n
	     && s1[i] != '\0'
	     && s2[i] != '\0'
	     && !result)
	{
	  result = s1[i] - s2[i];
	  i++;
	}
      if (i < n - 1 && s1[i] == '\0' && s2[i] != '\0')
	return (-100);
      else if (i < n - 1 && s2[i] == '\0' && s1[i] != '\0')
	return (100);
      else
	return (result);
    }
  return (0);
}
