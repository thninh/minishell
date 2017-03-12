/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:32:20 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/21 14:13:16 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabstrsize(char **array)
{
	int	i;

	if (array == NULL)
		return (0);
	i = 0;
	while (array[i] != NULL)
		i = i + 1;
	return (i);
}
