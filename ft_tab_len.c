/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:41:23 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/20 22:40:47 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_tab_len(char **env)
{
	int	i;

	if(env == NULL)
		return (0);
	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}