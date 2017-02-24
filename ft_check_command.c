/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:04:07 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 22:28:10 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_cmd_to_do(char **str_clean, char ***env)
{
	if (ft_strcmp(str_clean[0], "exit") == 0)
		return (ft_cmd_exit(str_clean, *env));
	else if (ft_strcmp(str_clean[0], "setenv") == 0)
		return(ft_cmd_setenv(str_clean, env));
	else if (ft_strcmp(str_clean[0], "unsetenv") == 0)
		return(ft_cmd_unsetenv(str_clean, env));
	else if (ft_strcmp(str_clean[0], "env") == 0)
		return(ft_print_env(str_clean, *env));
	else if (ft_strcmp(str_clean[0], "cd") == 0)
		return (ft_cmd_cd(env, str_clean));
	return (0);
}

char	ft_check_command(char *read, char ***env)
{
	char	***env_tmp;
	int		pid;

	env_tmp = NULL;
	env_tmp = env;
	if (read == NULL)
		return (0);
	pid = ft_do_execute(&read, env);
	waitpid(pid, NULL, 0);
	free(read);
	return (1);
}
