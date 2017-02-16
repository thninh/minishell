/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:38:33 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 17:18:05 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	int		argc_tmp;
	char **argv_tmp;
	char *read_tmp;
	char **str_to_wordtab;
	char **str_path;
	// int		i;
	char *path;
	int		path_num;
	char **str_complete;
	char *str_path_exec;

	argc_tmp = argc;
	argv_tmp = argv;
	while (42)
	{
		ft_printf("$>");
		read_tmp = NULL;
		str_complete = NULL;
		read_tmp = get_next_line(0);
		str_to_wordtab = ft_strsplit(read_tmp, ' ');
		// i = 0;
		// while (str_to_wordtab[i] != NULL)
		// {
		// 	// ft_printf("str_to_wordtab == %s\n", str_to_wordtab[i]);
		// 	i++;
		// }
		path = get_env(env, "PATH=");
		// ft_printf("path = %s\n", path);
		path_num = ft_path_num(path, ':');
		str_path = ft_recup_path_cut(path, path_num);
		str_complete = ft_join_path_and_str(str_path, path_num, str_to_wordtab);
//checker si ce qui est demandé est un builtin, si c'est un builtin
//il faut appliquer la fonction que j'aurai recodée type cd, echo, setenv,
// unsetend, env et exit.
// si ce n'est pas un builtin alors check de access et faire ce qui est demandé.
		str_path_exec = 0;
		str_path_exec = ft_check_access(str_complete);
		// ft_printf("str_path_exec %d\n", str_path_exec);
		ft_fork_exeve(env, str_path, str_to_wordtab, str_path_exec);
		free(read_tmp);
		ft_free_point_tab(str_to_wordtab);
		ft_free_point_tab(str_path);
		free(str_path_exec);
		free(path);
		ft_free_point_tab(str_complete);
	}

	return (0);
}
