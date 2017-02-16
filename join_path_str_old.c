/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:10:27 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 14:15:45 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_join_path_and_str(char **str_path, int path_num, char **str_to_wordtab)
{
	int		j;
	char	**str_complete;
	int		i;

	j = 0;
	str_complete = NULL;
	str_complete = (char **)malloc(sizeof(char *));
	i = 0;
	while (str_to_wordtab[j] != 0)
	{
		while (i < path_num)
		{
			str_complete[i] = str_path[i];
			i++;
		}
		str_complete[i + j] = str_to_wordtab[j];
		j++;
	}
	str_complete[i + j] = NULL;
	i = 0;
	while (str_complete[i] != NULL)
	{
		ft_printf("str_complete == %s\n", str_complete[i]);
		i++;
	}
	return (str_complete);
}
