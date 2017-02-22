/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 22:15:11 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/22 01:45:49 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cmd_cd(char ***env, char **str_to_worktab)
{
	if (ft_tabstrsize(str_to_worktab) > 2)
		ft_printf("cd: Too many arguments.\n");
	else
		*env = do_cd(*env, str_to_worktab);
	return (1);
}

int	ft_cmd_unsetenv(char **argv, char ***env)
{
  if (argv[1] != NULL)
      *env = ft_unsetenv(argv[1], *env);
  else
    ft_printf("unsetenv: Too few arguments.\n");
  return (1);
}

int	ft_cmd_setenv(char **str_to_worktab, char ***env)
{
	if (str_to_worktab[1] != NULL)
      {
        if (str_to_worktab[2] != NULL)
		*env = ft_setenv(str_to_worktab[1], str_to_worktab[2], *env);
        else
		*env = ft_setenv(str_to_worktab[1], "", *env);
      }
  else
    ft_printf("setenv: Too few arguments.\n");
  return (1);
}

int	ft_cmd_exit(char **argv, char **env)
{
  int		status;

  status = 0;
  if (argv[1] != NULL)
    status = ft_atoi(argv[1]);
  ft_free_point_tab(argv);
  ft_free_point_tab(env);
  exit(status);
  return (1);
}
