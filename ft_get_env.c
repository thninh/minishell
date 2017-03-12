/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:37:15 by Geekette          #+#    #+#             */
/*   Updated: 2017/03/11 12:59:55 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_name_total_name(char *name, char *total_name)
{
	free(name);
	free(total_name);
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
			ft_free_name_total_name(name, total_name);
			return (i);
		}
		i++;
	}
	ft_free_name_total_name(name, total_name);
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
	return (env_tmp);
}
