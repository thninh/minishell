/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:11:42 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 13:56:48 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_loopSetenv(char **str_to_worktab, char **env_tmp, int i)
{
	char	**str;

	str = ft_strsplit(env_tmp[i], '=');
	ft_bzero (str[1], ft_strlen(str[1]));
	str[0] = ft_strjoin(str[0], "=");
	env_tmp[i] = ft_strjoin(str[0], str_to_worktab[2]);
	ext_env = env_tmp;
	free(str);
	return;
}

void	ft_setenv_v1(char **str_to_worktab)
{
	char	**env_tmp;
	size_t	i;

	env_tmp = ft_env();
	i = 0;
	while (ext_env[i] != '\0')
	{
		if (ft_strncmp(env_tmp[i], str_to_worktab[1], ft_strlen(str_to_worktab[1])) == 0 \
			       	&& str_to_worktab[3] != 0)
			ft_loopSetenv(str_to_worktab, env_tmp, i);
		else if (ft_strncmp(ext_env[i], str_to_worktab[1], ft_strlen(str_to_worktab[1])) == 0 \
			       	&& str_to_worktab[3] == 0)
		{
			env_tmp[i] = ext_env[i];
			ext_env = env_tmp;
			return;
		}
		i++;
	}
	i--;
	env_tmp[i] = ft_strjoin(str_to_worktab[1], "=");
	env_tmp[i] = ft_strjoin(env_tmp[i], str_to_worktab[2]);
	i++;
	env_tmp[i] = NULL;
	ext_env = env_tmp;
	// ft_free_point_tab(env_tmp);
}

void	ft_setenv_v2(char *str_to_worktab_1)
{
	char		**env_tmp;
	size_t		i;

	env_tmp = ft_env();
	i = 0;
	while (ext_env[i] != '\0')
		i++;
	i--;
	env_tmp[i] = str_to_worktab_1;
	i++;
	env_tmp[i] = NULL;
	ext_env = env_tmp;
	// ft_free_point_tab(env_tmp);
}

void	ft_check_if_do_setenv(char **str_to_worktab)
{
	if (str_to_worktab[1] != NULL && str_to_worktab[2] != NULL)
		ft_setenv_v1(str_to_worktab);
	else if (str_to_worktab[2] == NULL)
		ft_setenv_v2(str_to_worktab[1]);
}
