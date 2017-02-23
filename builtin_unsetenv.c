/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:34:25 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 15:33:00 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	**ft_unsetenv(char *name, char **env)
// {
// 	int i;
//
// 	i = 0;
// 	if ((i = ft_get_in_env(name, env)) >= 0)
// 		env = ft_remove_from_array(i, env);
// 	return (env);
// }

char	**ft_unsetenv(char *name, char **env)
{
	int i_rm;
	int i;
	int len;
	char	**env_tmp;
	char	**env_tmp2;
	int j;

	i_rm = 0;
	len = 0;
	i = 0;
	j = 0;
	env_tmp = NULL;
	env_tmp2 = NULL;
	if ((i_rm = ft_get_in_env(name, env)) > 0)
	{
		len = ft_tabstrsize(env);
		env_tmp = (char **)malloc(sizeof(char *) * len);
		while (i < len)
		{
			if (i != i_rm)
			{
				env_tmp[j] = (char *)malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
				ft_strcpy(env_tmp[j], env[i]);
				j++;
			}
			if (i == i_rm)
			{
				// free(env[i]);
				i++;
			}
			i++;
		}
		env_tmp[j] = NULL;
		// free(env); /*ON REPREND DEPUIS LES DEBUT*/
		// ft_free_point_tab(env);
	}
	else
		ft_printf("%s is not in env\n");
	env_tmp2 = env_tmp;
	// ft_free_point_tab(env_tmp);
	return (env_tmp2);
}
