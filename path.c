/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:11:30 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 16:34:49 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_path_num(char const *str, char c)
{
	int count_str;
	int count_words;

	count_str = 0;
	count_words = 0;
	while (str[count_str])
	{
		if (str[count_str] != c && (count_str == 0 || str[count_str - 1] == c))
		{
			count_words++;
		}
		count_str++;
	}
	return (count_words);
}

char **ft_recup_path_cut(char *path, int path_num)
{
	char	**path_cut;
	int		j;
	int		i;

	path_cut = NULL;
	if (path != NULL)
	{
		i = 0;
		j = 0;
		while (i < path_num)
		{
			path_cut = ft_strsplit(path, ':');
			i++;
		}
	}
	// i = 0;
	// while (path_cut[i] != NULL)
	// {
	// 	ft_printf("path cut == %s\n", path_cut[i]);
	// 	i++;
	// }
	return (path_cut);
}
