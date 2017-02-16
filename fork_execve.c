/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:11:21 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 16:41:19 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char ft_fork_exeve(char **env, char **str_path, char **str_to_wordtab,
	char *str_path_exec)
{
	pid_t	father;
	char **str_path_tmp;

	str_path_tmp = str_path;
	father = fork();
	if (father > 0)
		ft_printf("on est dans le pere\n");
	if (father == 0)
	{
		ft_printf("on est dans le fils\n");
		execve(str_path_exec, str_to_wordtab, env);
	}
	return (0);
}
