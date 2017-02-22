/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:34:25 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/21 22:34:40 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(char *name, char **env)
{
	int i;

	i = 0;
	if ((i = ft_get_in_env(name, env)) >= 0)
		env = ft_remove_from_array(i, env);
	return (env);
}
