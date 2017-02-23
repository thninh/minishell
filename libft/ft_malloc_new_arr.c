/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_new_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:12:40 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 17:43:23 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_new_arr(char *str, char **arr)
{
	int		i;
	char	**new_arr;

	i = 0;
	while (arr[i] != NULL)
		i = i + 1;
	new_arr = (char**)malloc(sizeof(char*) * (i + 2));
	if (new_arr == NULL)
		return (arr);
	i = 0;
	while (arr[i] != NULL)
	{
		new_arr[i] = arr[i];
		i = i + 1;
	}
	free(arr);
	new_arr[i] = str;
	new_arr[i + 1] = NULL;
	return (new_arr);
}
