/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:26:01 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 14:17:10 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ext_env;

int main(int argc, char **argv, char **env)
{
	char		*line;
	char		*line_clean;
	char		**str_to_worktab;
	int			argc_tmp;
	char		**argv_tmp;

	argc_tmp = argc;
	argv_tmp = argv;
	ext_env = env;
	while (42)
	{
		line_clean = NULL;
		str_to_worktab = NULL;
		line = NULL;
		ft_printf("$>");
		line = get_next_line(0);
		line_clean = ft_strtrim(line); /*que les espaces? gerer les tab?*/
		if (ft_strlen(line_clean) > 0)
		{
			str_to_worktab = ft_strsplit(line, ' ');
			ft_check_if_is_builtin(str_to_worktab, line);
			// ft_free_point_tab(str_to_worktab);
		}
		free(line_clean);
		free(line);
		// if (ft_strcmp(str_to_worktab[0], "env") == 0)
			ft_free_point_tab(str_to_worktab);
	}
	ft_free_point_tab(ext_env);
	return (0);
}
