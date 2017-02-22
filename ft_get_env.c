/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:37:15 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/22 02:05:33 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



char	*ft_check_path(char *str_to_worktab1, char *dir)
{
	int		total_len;
	char	*path;

	total_len = ft_strlen(str_to_worktab1) + ft_strlen(dir) + 2;
	path = (char *)malloc(sizeof(char) * total_len);
	if (!path)
		return (path);
	ft_strcpy(path, dir);
	ft_strcat(path, "/");
	ft_strcat(path, str_to_worktab1);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	path = NULL;
	return (path);
}

int	my_str_is_in(char *str, char *to_find)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (str[i] != '\0')
    {
      while ((str[i] == to_find[a]) && ((str[i] != '\0') || (to_find[a] != '\0')))
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



char		*ft_get_path(char *str_to_worktab1, char **env)
{
  int		i;
  char		*path;
  char		**a_path;
  char		*p_bin;

  path = NULL;
  a_path = NULL;
  if ((i = ft_get_in_env("PATH", env)) >= 0)
    path = env[i] + 5;
  i = 0;
  a_path = ft_strsplit(path, ':');
  if (path != NULL && a_path != NULL)
      {
	i = 0;
	while (a_path[i] != NULL)
	  {
	    if ((p_bin = ft_check_path(str_to_worktab1, a_path[i])) != NULL)
	      {
		ft_free_point_tab(a_path);
		return (p_bin);
	      }
	    i = i + 1;
	  }
      }
  return (str_to_worktab1);
}

int	ft_get_in_env(char *data, char **env)
{
	int			i;
	char		*path;
	char **env_tmp;

	i = 0;
	path = NULL;
	env_tmp = NULL;
	env_tmp = env;
 	while (env_tmp[i] != NULL)
	{
		if (my_str_is_in(env_tmp[i], data) != 0)
		{
			path = my_path_dup(env_tmp[i], ft_strlen(data), ft_strlen(env_tmp[i]));
			return (i);
		}
		i++;
	}
	return (0);
}

char	**ft_get_env(char **env)
{
	char	**env_tmp;
	int		tab_len;
	int		str_len;
	int		i;

	tab_len = 0;
	tab_len = ft_tab_len(env);
	env_tmp = NULL;
	env_tmp = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!env_tmp)
		return (env_tmp);
	i = 0;
	while (i < tab_len)
	{
		str_len = ft_strlen(env[i]);
		env_tmp[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (env_tmp[i] != NULL)
			ft_strcpy(env_tmp[i], env[i]);
		i++;
	}
	env_tmp[i] = NULL;
	return(env_tmp);
}
