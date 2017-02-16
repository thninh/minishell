/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:40:38 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 16:36:31 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX 1024
# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>
# include <sys/wait.h>
# include "./libft/libft.h"

int		main(int argc, char **argv, char **env);
char	*get_env(char **env, char *data);
char	*my_path_dup(char *str, int i, int j);
int		my_str_is_in(char *str, char *to_find);
int		ft_path_num(char const *str, char c);
char	**ft_recup_path_cut(char *path, int path_num);
char	**ft_join_path_and_str(char **str_path, int path_num, char **str_to_wordtab);
int		ft_tabstrsize(char **str_to_wordtab);
char	*ft_check_access(char **str_complete);
char	ft_fork_exeve(char **env, char **str_path, char **str_to_wordtab,
		char *str_path_exec);


#endif
