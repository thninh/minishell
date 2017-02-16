/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:32:20 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 12:38:13 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabstrsize(char **str_to_wordtab)
{
	int	i;

	i = 0;
	while (str_to_wordtab[i] != NULL)
		i++;
	return (i);
}
