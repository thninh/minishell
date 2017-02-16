/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:19:12 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:55 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_check_exist(char *str_complete)
{
	char check_access;

	check_access = 0;
	check_access = access(str_complete, F_OK);
	if (check_access == 0)
		ft_printf("%s exist\n", str_complete);
	else
	{
		ft_printf("%s not exist\n", str_complete);
		return (0);
	}
	return (1);
}

char	ft_check_read(char *str_complete)
{
	char check_access;

	check_access = 0;
	check_access = access(str_complete, R_OK);
	if (check_access == 0)
		ft_printf("%s can be read\n", str_complete);
	else
	{
		ft_printf("%s can't be read\n", str_complete);
		return (0);
	}
	return (1);
}

char	ft_check_write(char *str_complete)
{
	char check_access;

	check_access = 0;
	check_access = access(str_complete, W_OK);
	if (check_access == 0)
		ft_printf("%s can be write\n", str_complete);
	else
	{
		ft_printf("%s can't be write\n", str_complete);
		return (0);
	}
	return (1);
}

char	ft_check_exec(char *str_complete)
{
	char check_access;

	check_access = 0;
	check_access = access(str_complete, X_OK);
	if (check_access == 0)
	{
		// ft_printf("%s can be exec\n", str_complete);
		return (1);
	}
	else
	{
		// ft_printf("%s can't be exec\n", str_complete);
		return (0);
	}
	return (1);
}

char	*ft_check_access(char **str_complete)
{
	// char	check_access_exist;
	// char	check_access_read;
	// char	check_access_write;
	char	check_access_exec;
	int	i;

	i = 0;
	while (str_complete[i] != NULL)
	{
		// check_access_exist = ft_check_exist(str_complete[i]);
		// check_access_read = ft_check_read(str_complete[i]);
		// check_access_write = ft_check_write(str_complete[i]);
		if ((check_access_exec = ft_check_exec(str_complete[i])) != 0)
			return (str_complete[i]);
		i++;
	}
	return (0);
}
