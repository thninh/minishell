/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:34:25 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 09:17:25 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv2(char **env_tmp, char **env, int i_rm, int len)
{
	int i = 0;
	int j = 0;

	while (i < len)
	{
		if (i != i_rm)
		{
			env_tmp[j] = (char *)malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
			ft_strcpy(env_tmp[j], env[i]);
			j++;
			i++;
		}
		else if (i == i_rm)
			i++;
	}
	env_tmp[j] = NULL;
	return (env_tmp);
}

char	**ft_unsetenv(char *name, char **env)
{
	int		i_rm;
	int		len;
	char	**env_tmp;

	i_rm = 0;
	len = 0;
	env_tmp = NULL;
	i_rm = ft_get_in_env(name, env);
	len = ft_tabstrsize(env);
	env_tmp = (char **)malloc(sizeof(char *) * len);
	env_tmp = ft_unsetenv2(env_tmp, env, i_rm, len);
	return (env_tmp);
}
