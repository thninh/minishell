/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:54:21 by Geekette          #+#    #+#             */
/*   Updated: 2017/03/11 12:53:16 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_read(char ***env)
{
	char	*read;

	ft_printf("=== Bienvenue dans le minishell très basique de cprouveu ===\n");
	ft_printf("$>");
	while (42)
	{
		read = NULL;
		if ((read = get_next_line(0)))
		{
			ft_check_command(read, env);
			ft_printf("$>");
		}
	}
	return (1);
}
