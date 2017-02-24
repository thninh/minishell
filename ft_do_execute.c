/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:20:10 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 22:28:22 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int		ft_child(char **str_to_worktab_split, char **env)
{
	char	*path;
	char *check_path;
	int i;

	i = 0;
	path = NULL;
	check_path = NULL;
	if ((ft_strncmp(str_to_worktab_split[0], "/", 1)) == 0)
		check_path = str_to_worktab_split[0];
	else
		check_path = ft_get_path(str_to_worktab_split[0], env);
	if (execve(check_path, str_to_worktab_split, env) < 0)
	{
		ft_printf("%s: command not found\n", str_to_worktab_split[0]);
		return (0);
	}
	return (1);
}

int		ft_pid(pid_t pid, char **str_clean, char ***env)
{
	if (pid == 0)
	{
		if (!ft_child(str_clean, *env))
		{
			ft_free_point_tab(str_clean);
			exit (EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_free_point_tab(str_clean);
		return (pid);
	}
	return (-1);
}

int		ft_do_execute(char **str_to_worktab, char ***env)
{
	char	**str_clean;
	pid_t	pid;

	pid = 0;
	if (ft_strncmp(*str_to_worktab, "echo", 4) == 0)
	{
		str_clean = ft_strsplit(*str_to_worktab, ' ');
		ft_echo(str_clean);
		ft_free_point_tab(str_clean);
	}
	else if ((str_clean = ft_clean_str(str_to_worktab)) != NULL)
	{
		if (!ft_check_cmd_to_do(str_clean, env))
		{
			if ((pid == fork()) > 0)
				pid = ft_pid(pid, str_clean, env);
		}
		ft_free_point_tab(str_clean);
	}
	return (-1);
}
