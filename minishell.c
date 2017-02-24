/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:26:01 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 11:19:44 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**env_tmp;
	char	**argv_tmp;
	int		argc_tmp;

	argv_tmp = argv;
	argc_tmp = argc;
	env_tmp = ft_get_env(env);
	while (ft_read(&env_tmp) > 0);
	ft_free_point_tab(env_tmp);
	return (0);
}
