/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:37:15 by Geekette          #+#    #+#             */
/*   Updated: 2017/03/11 14:49:14 by cprouveu         ###   ########.fr       */
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

char	*ft_path(char **env, char *path)
{
	int i;

	i = 0;
	if ((i = ft_get_in_env("PATH", env)) >= 0)
		path = env[i] + 5;
	else
		ft_printf("PATH not found\n");
	return (path);
}

char	*ft_get_path2(char *path, char *str_to_worktab1)
{
	int		i;
	char	**a_path;
	char	*p_bin;

	i = 0;
	if (path)
	{
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
		if (a_path)
			ft_free_point_tab(a_path);
	}
	return (str_to_worktab1);
}

char	*ft_get_path(char *str_to_worktab1, char **env)
{
	char	*path;
	char	*ret;

	path = NULL;
	path = ft_path(env, path);
	ret = ft_get_path2(path, str_to_worktab1);
	return (ret);
}
