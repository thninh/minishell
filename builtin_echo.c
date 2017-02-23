/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:16 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 00:04:43 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_echo_check_if_eof(char **str_to_worktab)
{
	if (*++str_to_worktab != '\0')
		ft_printf(" ");
	else
		ft_printf("\n");
	return (str_to_worktab);
}

char	**ft_echo4(char **str_tmp, char **str_to_worktab)
{
	str_tmp = ft_strsplit(*str_to_worktab, '"');
	ft_printf("%s", *str_tmp);
	return (str_tmp);
}

char	**ft_echo3(char **str_tmp, char **str_to_worktab)
{
	str_tmp = ft_strsplit(*str_to_worktab, '\'');
	ft_printf("%s", *str_tmp);
	return (str_tmp);
}

char	**ft_echo2(char **str_tmp, char **str_to_worktab)
{
	str_tmp = ft_strsplit(*str_to_worktab, '"');
	ft_printf("%s", *str_tmp);
	return (str_tmp);
}

void	ft_echo(char **str_to_worktab)
{
	int		i;
	char	**str_tmp;

	i = 0;
	str_to_worktab++;
	while (*str_to_worktab != '\0')
	{
		if (ft_strncmp(*str_to_worktab, "\"", 1) == 0)
		{
			str_tmp = ft_echo2(str_tmp, str_to_worktab);
			str_to_worktab = ft_echo_check_if_eof(str_to_worktab);
		}
		else if (ft_strncmp(*str_to_worktab, "'", 1) == 0)
		{
			str_tmp = ft_echo3(str_tmp, str_to_worktab);
			str_to_worktab = ft_echo_check_if_eof(str_to_worktab);
		}
		else if (!(ft_strncmp(*str_to_worktab, "\"", 1) == 0) &&
			!(ft_strncmp(*str_to_worktab, "'", 1) == 0))
		{
			str_tmp = ft_echo4(str_tmp, str_to_worktab);
			str_to_worktab = ft_echo_check_if_eof(str_to_worktab);
		}
		ft_free_point_tab(str_tmp);
	}
}
