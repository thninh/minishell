/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:02:23 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 00:25:07 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_env(char **str_clean, char **env)
{
	int i;
	char **env_tmp;

	env_tmp = NULL;
	env_tmp = ft_get_env(env);
	if (str_clean[1] != NULL)
		ft_printf("Sorry, but env didn't suppose any arguments.\n");
	else
	{
		i = 0;
		while (env_tmp[i])
		{
			ft_printf("%s\n", env_tmp[i]);
			i++;
		}
	}
	ft_free_point_tab(env_tmp);
	return(1);
}
