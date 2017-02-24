/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:46:14 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/24 09:18:10 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	*ft_clean(char *str, char *str2, int n)
{
	char	*result;
	int		total_len;

	total_len = ft_strlen(str) + ft_strlen(str2) + 1;
	result = (char *)malloc(sizeof(char) * total_len);
	if (result != NULL)
	{
		if (str != NULL)
		{
			ft_strcpy(result, str);
			ft_strncat(result, str2, n);
			free(str);
		}
		else
			ft_strncpy(result, str2, n);
		return (result);
	}
	return (str);
}

char	**ft_clean_str(char **str_to_worktab)
{
	char	**str_split;

	str_split = ft_split_str_multi_char(*str_to_worktab, " \t\n", 1);
	return (str_split);
}
