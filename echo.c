/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:54:49 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/17 19:03:47 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **str_to_worktab)
{
	int		i;
	char	**str_tmp;

	i = 0;
	str_tmp = NULL;
	str_to_worktab++;
	while (*str_to_worktab != '\0')
	{
		if (ft_strncmp(*str_to_worktab, "\"", 1) == 0)
		{
			str_tmp = ft_strsplit(*str_to_worktab, '"');
			ft_printf("%s", *str_tmp);
			if (*++str_to_worktab != '\0')
				ft_printf(" ");
			else
				ft_printf("\n");

		}
		else if (ft_strncmp(*str_to_worktab, "'", 1) == 0)
		{
			str_tmp = ft_strsplit(*str_to_worktab, '\'');
			ft_printf("%s", *str_tmp);
			if (*++str_to_worktab != '\0')
				ft_printf(" ");
			else
				ft_printf("\n");

		}
		else if (!(ft_strncmp(*str_to_worktab, "\"", 1) == 0) &&
			!(ft_strncmp(*str_to_worktab, "'", 1) == 0))
		{
			str_tmp = ft_strsplit(*str_to_worktab, '"');
			ft_printf("%s", *str_tmp);
			if (*++str_to_worktab != '\0')
				ft_printf(" ");
			else
				ft_printf("\n");
		}
		ft_free_point_tab(str_tmp);
	}
}
