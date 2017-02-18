/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:58:07 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 14:02:14 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_if_is_builtin(char **str_to_worktab, char *line)
{
	char *line_tmp;

	line_tmp = NULL;
	line_tmp = line;
	if (ft_strcmp(*str_to_worktab, "exit") == 0)
		exit(0);
	else if(ft_strcmp(*str_to_worktab, "echo") == 0)
		ft_echo(str_to_worktab);
	else if(ft_strcmp(*str_to_worktab, "cd") == 0)
		ft_printf("on est dans cd\n");
	else if(ft_strcmp(*str_to_worktab, "setenv") == 0)
		ft_check_if_do_setenv(str_to_worktab);
	else if(ft_strcmp(*str_to_worktab, "unsetenv") == 0)
		ft_unsetenv(str_to_worktab[1]);
	else
		ft_execute(str_to_worktab);
}
