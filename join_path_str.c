/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:10:27 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/16 17:19:38 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_join_path_and_str(char **str_path, int path_num, char **str_to_wordtab)
{
	int		i;
	char	**str_complete;
	char	*str_tmp;

	i = 0;
	str_complete = NULL;
	str_complete = (char **)malloc(sizeof(char *) * path_num + 1);
	str_tmp = ft_strjoin("/", str_to_wordtab[0]);
	// ft_printf("str_tmp %s\n", str_tmp);
	while (i < path_num)
	{
		// ft_printf("str_path %s\n", str_path[i]);
		str_complete[i] = ft_strjoin(str_path[i], str_tmp);
		// ft_printf("str_complete %s\n", str_complete[i]);
		i++;
	}
	// i = 0;
	// while (str_complete[i] != NULL)
	// {
	// 	ft_printf("str_complete == %s\n", str_complete[i]);
	// 	i++;
	// }
	free(str_tmp);
	return (str_complete);
}
