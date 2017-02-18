/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:40:38 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 10:17:41 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX 1024
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"

extern char	**ext_env;


int		main(int argc, char **argv, char **env);
void	ft_check_if_is_builtin(char **str_to_worktab, char *line);
void	ft_echo(char **str_to_worktab);
char	**ft_env();
void	ft_env_tmp(char **env, char *env_tmp);
char	**ft_print_env(char **env);
void	ft_check_if_do_setenv(char **str_to_worktab);
void	ft_setenv_v2(char *str_to_worktab_1);
void	ft_setenv_v1(char **str_to_worktab);
void	ft_loopSetenv(char **str_to_worktab, char **env_tmp, int i);
void	ft_execute(char **str_to_worktab);
void	ft_do_execute(char *path, char **str_to_worktab);
char	*ft_check_path(char *arg);
char	*ft_get_in_env(char *data);
char	*my_path_dup(char *str, int i, int j);
int		my_str_is_in(char *str, char *to_find);
void	ft_unsetenv (char *str_to_worktab_1);

#endif
