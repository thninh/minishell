/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:41:17 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 14:01:20 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	ft_do_execute(char *path, char **str_to_worktab)
{
	pid_t		pid;
	int			status;
	extern char	**ext_env;

	pid = 0;
	pid = fork();
	status = 0;
	if (pid == 0)
	{
		if (execve(path, str_to_worktab, ext_env) == -1)
		{
			ft_printf("Error, execve failed.\n");
			exit(1);
		}
	}
	else if (pid == -1)
	{
		ft_printf("Error forking.\n");
		exit(1);
	}
	else
	{
		if ((pid = waitpid(pid, &status, 0)) < 0)
			ft_printf("waitpid error.\n");
	}
}

void	ft_execute(char **str_to_worktab)
{
	char	*path;

	path = ft_check_path(*str_to_worktab);
	ft_do_execute(path, str_to_worktab);
	free(path);
}
