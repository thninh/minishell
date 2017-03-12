/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:40:38 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 22:28:52 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX 1024
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"

# include <stdio.h>

int		main(int argc, char **argv, char **env);
int		ft_check_cmd_to_do(char **str_clean, char ***env);
char	ft_check_command(char *read, char ***env);
char	*ft_clean(char *str, char *str2, int n);
int		ft_replace_dollar(char **str_to_worktab_split, char **env);
void	ft_replace_wave(char **str_to_worktab_split, char **env);
int		ft_replace_quote(char **str_to_worktab_split, char **env, int doubled);
char	**ft_clean_str(char **str_to_worktab);
int		ft_do_execute(char **str_to_worktab, char ***env);
char	*ft_check_path(char *str_to_worktab1, char *dir);
char	*ft_get_path(char *str_to_worktab1, char **env);
char	*ft_get_var_value(char *result, int *i, char *str, char **env);
char	*ft_get_home_dir(char **env);
int		ft_get_in_env(char *name, char **env);
char	**ft_get_env(char **env);
int		ft_read(char ***env);
int		ft_tab_len(char **env);
int		ft_command_exit(char **argv, char **env);
void	ft_echo(char **str_to_worktab);
int		ft_cmd_unsetenv(char **argv, char ***env);
int		ft_cmd_setenv(char **argv, char ***env);
int		ft_cmd_exit(char **argv, char **env);
int		ft_cmd_cd(char ***env, char **str_to_worktab);
char	**ft_check_if_do_setenv(char **str_to_worktab, char **env);
char	**ft_setenv(char *name, char *value, char **env);
char	**ft_unsetenv(char *name, char **env);
char	**copy_array_without(int index, char **new_arr, char **arr, int len);
char	**ft_setenv_env2(char *str, char **arr);
char	**ft_setenv_env(char *str, char **arr);
int		ft_print_env(char **str_clean, char **env);
int		ft_child(char **str_to_worktab_split, char **env);
char	**do_cd(char **env, char **str_to_worktab);

#endif
