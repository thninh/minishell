/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:47:07 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 15:02:41 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_change_pwd_and_oldpwd(char **env, char *dir)
{
	char **env_tmp;
	char *old_pwd;
	int	i;

	env_tmp = NULL;
	env_tmp = ft_get_env(env);
	old_pwd = NULL;
	i = 0;
	if ((i = ft_get_in_env("PWD", env_tmp)) >= 0)
		old_pwd = env[i] + 4;
	i = 0;
	if ((i = ft_get_in_env("OLDPWD", env_tmp)) >= 0)
	{
		env_tmp = ft_unsetenv("OLDPWD", env_tmp);
		env_tmp = ft_unsetenv("PWD", env_tmp);
		env_tmp = ft_setenv("PWD", dir, env_tmp);
		env_tmp = ft_setenv("OLDPWD", old_pwd, env_tmp);
	}
	return (env_tmp);
}

//// 1 leak en moins mais fait bugger cd
// char	**ft_change_pwd_and_oldpwd(char **env, char *dir)
// {
// 	char *old_pwd;
// 	int	i;
//
// 	old_pwd = NULL;
// 	i = 0;
// 	if ((i = ft_get_in_env("PWD", env)) >= 0)
// 		old_pwd = env[i] + 4;
// 	i = 0;
// 	if ((i = ft_get_in_env("OLDPWD", env)) >= 0)
// 	{
// 		env = ft_unsetenv("OLDPWD", env);
// 		env = ft_unsetenv("PWD", env);
// 		env = ft_setenv("PWD", dir, env);
// 		env = ft_setenv("OLDPWD", old_pwd, env);
// 	}
// 	return (env);
// }



////

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

char	**do_cd(char **env, char **str_to_worktab)
{
	char	*dir;
	int		i;
	int		j;
	int n;

	i = 1;
	j = 0;
	n = 0;
	dir = NULL;
	if (ft_tabstrsize(str_to_worktab) == 1)
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
	}
	else
	{
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
	}
	env = ft_change_pwd_and_oldpwd(env, dir);
	return (env);
}
