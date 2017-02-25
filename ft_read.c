/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:54:21 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/25 12:33:18 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_read(char ***env)
{
	char	*read;

	ft_printf("===== Bienvenue dans le minishell très basique de cprouveu =====\n");
	ft_printf("$>");
	while ((read = get_next_line(0)))
	{
		ft_check_command(read, env);
		ft_printf("$>");
	}
	// read = NULL;
	// while (42)
	// {
	// 	if (get_next_line(0, &read))
	// 	{
	// 		ft_check_command(read, env);
	// 		ft_printf("$>");
	// 	}
	// }
	free(read);
	if (read == 0)
	{
		ft_printf("env EMPTY, retry\n");
		ft_printf("====    Vous quittez mon minishell   =====\n");
		ft_printf("====            Have FUN             =====\n");
		ft_printf("==== 42 is the answer for everything =====\n");
		exit(EXIT_FAILURE);
	}
	ft_free_point_tab(*env);
	return (1);
}
