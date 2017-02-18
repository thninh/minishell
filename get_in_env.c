/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:51:21 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 13:03:15 by Geekette         ###   ########.fr       */
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
  dup = (char *)malloc(sizeof(char) * (j - i + 1));
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

char	*ft_get_in_env(char *data)
{
	int			i;
	// extern char	**ext_env;
	char		*path;

	i = 0;
	path = NULL;
 	while (ext_env[i] != NULL)
	{
		if (my_str_is_in(ext_env[i], data) != 0)
		{
			path = my_path_dup(ext_env[i], ft_strlen(data), ft_strlen(ext_env[i]));
			return (path);
		}
		++i;
	}
	return (NULL);
}
