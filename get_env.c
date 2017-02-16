/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:51:21 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 17:10:43 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_str_is_in(char *str, char *to_find)
{
  int	save;
  int	i;
  int	a;

  a = 0;
  i = 0;
  save = 0;
  while (str[i] != '\0')
    {
      save = i;
      while ((str[i] == to_find[a]) && ((str[i] != '\0')
                                        || (to_find[a] != '\0')))
        {
          i++;
          a++;
        }
      if (to_find[a] == '\0')
        return (1);
      a = 0;
      i++;
    }
  return (0);
}

char	*my_path_dup(char *str, int i, int j)
{
  char	*dup;
  int	k;

  k = 0;
  dup = malloc((j - i + 1) * sizeof(*dup));
  if (dup == NULL)
    {
		ft_printf("malloc failed");
		return (0);
	}
  while (str[i] != '\0')
    {
      dup[k] = str[i];
      ++i;
      ++k;
    }
  dup[k] = '\0';
  return (dup);
}

char	*get_env(char **env, char *data)
{
  int   i;
  char  *search;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_str_is_in(env[i], data) != 0)
	{
	  search = my_path_dup(env[i], ft_strlen(data), ft_strlen(env[i]));
	  return (search);
	}
      ++i;
    }
  return (NULL);
}
