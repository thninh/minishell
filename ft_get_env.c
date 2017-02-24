/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:37:15 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 19:06:48 by Geekette         ###   ########.fr       */
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

char	*ft_get_path(char *str_to_worktab1, char **env)
{
	int		i;
	char	*path;
	char	**a_path;
	char	*p_bin;

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

int		ft_get_in_env(char *data, char **env)
{
	int		i;
	char	**env_tmp;
	char	*name;
	char	*total_name;

	i = 0;
	env_tmp = NULL;
	env_tmp = env;
	while (data[i] && data[i] != '=')
		i++;
	name = ft_strsub(data, 0, i);
	total_name = ft_strjoin(name, "=");
	i = 0;
	while (env_tmp[i] != NULL)
	{
		if (ft_strncmp(env_tmp[i], total_name, ft_strlen(total_name)) == 0)
		{
			free(name);
			free(total_name);
			return (i);
		}
		i++;
	}
	free(name);
	free(total_name);
	return (-1);
}

char	**ft_get_env(char **env)
{
	char	**env_tmp;
	int		tab_len;
	int		str_len;
	int		i;

	tab_len = 0;
	tab_len = ft_tabstrsize(env);
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
