/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_word_to_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:55:37 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 17:38:04 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_add_word_to_tab(char *str, int count, char **arr)
{
	char		*elem;

	elem = (char *)malloc(sizeof(char) * (count + 1));
	if (elem != NULL)
	{
		ft_strncpy(elem, str, count);
		elem[count] = '\0';
		return (ft_add_word_to_arr(elem, arr));
	}
	return (arr);
}
