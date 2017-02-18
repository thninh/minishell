/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:50:00 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/18 11:24:32 by Geekette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_path(char *str_to_worktab)
{
	size_t	i;
	char	*path;
	char	*old_path;
	char	**path_split;
	char	*path_complete;

	i = 0;
	path = NULL;
	path_split = NULL;
	if (access(str_to_worktab, F_OK) == 0)
		return (str_to_worktab);
	path = ft_get_in_env("PATH=");
	path_split = ft_strsplit(path, ':');
	while (path_split[i] != '\0')
	{
		old_path = ft_strjoin(path_split[i], "/");
		free(path);
		path = old_path;
		path_complete = ft_strjoin(path, str_to_worktab);
		if (access(path_complete, F_OK) == 0)
			{
				free(path);
				ft_free_point_tab(path_split);
				return (path_complete);
			}
		i++;
		free(path_complete);
	}
	free(path);
	free(path_split);
	return (0);
}
