/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:11:42 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/22 02:04:49 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_setenv_env2(char *str, char **arr)
{
  int		i;
  char		**new_arr;

  i = 0;
  while (arr[i] != NULL)
    i = i + 1;
  new_arr = (char**)malloc(sizeof(char*) * (i + 2));
  if (new_arr == NULL)
    return (arr);
  i = 0;
  while (arr[i] != NULL)
    {
      new_arr[i] = arr[i];
      i = i + 1;
    }
if (arr != NULL)
  free(arr);
  new_arr[i] = str;
  new_arr[i + 1] = NULL;
  return (new_arr);
}

char		**ft_setenv_env(char *str, char **arr)
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
    return (ft_setenv_env2(str, arr));
  return (new_arr);
}

char		**ft_setenv(char *name, char *value, char **env)
{
	int		i;
    int		total_len;
    char		*record;

	i = 0;
    total_len = ft_strlen(name) + ft_strlen(value) + 2;
    record = (char*)malloc(sizeof(char) * total_len);
    if (record != NULL)
      {
		  if (!(ft_strcmp(value, "") == 0))
		  {
        ft_strcpy(record, name);
        ft_strcat(record, "=");
        ft_strcat(record, value);
		}
		else
			ft_strcpy(record, name);
        if (ft_get_in_env(name, env))
		{
			free(env[i]);
			env[i] = record;
		}
        else
			return (ft_setenv_env(record, env));
      }
    return (env);
}
