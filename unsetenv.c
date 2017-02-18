/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:34:25 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 14:29:02 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv (char *str_to_worktab_1)
{
	char	**env_tmp;
	size_t	i;
	size_t	size;

	size = 0;
	while (ext_env[size] != '\0')
		size++;
	env_tmp = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (ext_env[i] != '\0')
	{
		if (ft_strncmp(ext_env[i], str_to_worktab_1, ft_strlen(str_to_worktab_1)) != 0)
			env_tmp[i] = ft_strdup(ext_env[i]);
		i++;
	}
	env_tmp[i] = NULL;
	ft_free_point_tab(ext_env);
	ext_env = env_tmp;
}
