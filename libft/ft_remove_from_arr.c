/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_from_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:25:00 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 17:58:05 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_array_without(int rem, char **new_arr, char **arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != rem)
		{
			new_arr[j] = (char*)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1));
			if (new_arr[j])
			{
				ft_strcpy(new_arr[j], arr[i]);
				j = j + 1;
			}
		}
		i = i + 1;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char	**ft_remove_from_array(int rem, char **arr)
{
	int		len;
	char	**new_arr;

	new_arr = NULL;
	if (arr != NULL)
	{
		len = ft_tabstrsize(arr);
		new_arr = (char**)malloc(sizeof(char*) * (len));
		new_arr = ft_copy_array_without(rem, new_arr, arr, len);
		ft_free_point_tab(arr);
	}
	return (new_arr);
}
