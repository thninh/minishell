/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:02:25 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 11:49:05 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
	return (env);
}

void	ft_env_tmp(char **env_tp, char *env_tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen(env_tmp);
	while (env_tp[j] != '\0')
	{
		if (ft_strncmp(env_tp[j], env_tmp, i) == 0)
		{
			ft_printf(env_tp[j]);
			return;
		}
		j++;
	}
}

char	**ft_env()
{
	size_t	i;
	char	**env_tmp;
	size_t	size_of_env;

	i = 0;
	size_of_env = 0;
	while (ext_env[size_of_env] != '\0')
		size_of_env++;
	env_tmp = (char **)malloc(sizeof(char *) * (size_of_env + 2));
	while (ext_env[i] != '\0')
	{
		env_tmp[i] = ft_strdup(ext_env[i]);
		i++;
	}
	env_tmp[i] = NULL;
	return (env_tmp);
}
