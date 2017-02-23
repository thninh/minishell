/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:47:07 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 00:26:50 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_change_pwd_and_oldpwd(char **env, char *dir)
{
	char **env_tmp;
	char *old_pwd;
	int	i;
	char	**tmp;

	env_tmp = NULL;
	env_tmp = ft_get_env(env);
	old_pwd = NULL;
	i = 0;
	if ((i = ft_get_in_env("PWD", env_tmp)) >= 0)
		old_pwd = env[i] + 4;
	i = 0;
	if ((i = ft_get_in_env("OLDPWD", env_tmp)) >= 0)
	{
		tmp = ft_unsetenv("OLDPWD", env_tmp);
		ft_free_point_tab(env_tmp);
		env_tmp = ft_unsetenv("PWD", tmp);
		ft_free_point_tab(tmp);
		tmp = ft_setenv("PWD", dir, env_tmp);
		env_tmp = ft_setenv("OLDPWD", old_pwd, tmp);
	}
	return (env_tmp);
}

char	**exec_cd(char **env, char *dir, int f)
{
	if (access(dir, F_OK) != 0)
	{
		ft_putstr(dir);
		ft_putstr(": No such file or directory.\n");
	}
	else
	{
		if (chdir(dir) == -1)
		{
			ft_putstr(dir);
			ft_putstr(": Permission denied.\n");
		}
	}
	if (f == 1)
	free(dir);
	return (env);
}

char	*do_cd3(char **str_to_worktab, char *dir, char **env, int i)
{
	int	n;
	int	j;

	j = 0;
	n = 0;
	if ((i = ft_strcmp("-", str_to_worktab[1])) < 0)
		dir = str_to_worktab[1];
	if ((j = ft_strcmp("-", str_to_worktab[1])) >= 0)
	{
		if ((n = ft_get_in_env("OLDPWD", env)) >= 0)
			dir = env[n] + 7;
	}
	if (dir == NULL)
		ft_putstr("cd: can't find OLDPWD.\n");
	else
		exec_cd(env, dir, i);
	return (dir);
}

char	*do_cd2(char **env, char *dir, int i)
{
	if (*env != NULL)
	{
		if ((i = ft_get_in_env("HOME", env)) >= 0)
			dir = env[i] + 5;
	}
	if (dir == NULL)
		ft_printf("cd: HOME not set\n");
	else
		exec_cd(env, dir, i);
	return (dir);
}

char	**do_cd(char **env, char **str_to_worktab)
{
	char	*dir;
	int		i;
	char	**tmp;

	i = 1;
	dir = NULL;
	if (ft_tabstrsize(str_to_worktab) == 1)
		dir = do_cd2(env, dir, i);
	else
		dir = do_cd3(str_to_worktab, dir, env, i);
	if (dir)
	{
		tmp = env;
		env = ft_change_pwd_and_oldpwd(tmp, dir);
		ft_free_point_tab(tmp);
	}
	return (env);
}
