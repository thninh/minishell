/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:54:21 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/21 15:39:46 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_read(char ***env)
{
	char	*read;

	ft_printf("$>");
	while ((read = get_next_line(0)))
	{
		ft_check_command(read, env);
		ft_printf("$>");
	}
	free(read);
	ft_free_point_tab(*env);
	return (1);
}
