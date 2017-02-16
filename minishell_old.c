/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:38:33 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/15 20:45:00 by Geekette         ###   ########.fr       */
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

char **ft_recup_path_cup(char *path, int path_num)
{
	char	**path_cut_tmp;
	char	**path_cut;
	int		j;
	int		i;

	path_cut = NULL;
	path_cut_tmp = (char **)malloc(sizeof(char *));
	if (path != NULL)
	{
		i = 0;
		j = 0;
		while (i < path_num)
		{
			path_cut_tmp = ft_strsplit(path, ':');
			i++;
		}
	}
	i = 0;
	while (path_cut_tmp[i] != NULL)
	{
		ft_printf("path cut == %s\n", path_cut_tmp[i]);
		i++;
	}
	path_cut = path_cut_tmp;
	free(path_cut_tmp);
	return (path_cut);
}

int	main(int argc, char **argv, char **env)
{
	int argc_tmp;
	char **argv_tmp;
	char *path;
	int		path_num;
	char **str_to_wordtab;
	char **str_complete;
	int i;
	int j;
	char *read_tmp;
	char *tmp_save_firth_path;

	argc_tmp = argc;
	argv_tmp = argv;
	path_num = 0;
	j = 0;

	while (42)
	{
		read_tmp = NULL;
		str_complete = NULL;
		str_complete = (char **)malloc(sizeof(char *));
		str_to_wordtab = NULL;
		str_to_wordtab = (char **)malloc(sizeof(char *));
		tmp_save_firth_path = NULL;
		i = 1;
		ft_printf("$>");
		read_tmp = get_next_line(0);
		ft_printf("str recup => %s\n", read_tmp);
		str_to_wordtab = ft_strsplit(read_tmp, ' ');
		i = 0;
		while (str_to_wordtab[i] != NULL)
			ft_printf("str_to_wordtab == %s\n", str_to_wordtab[i++]);
		path = get_env(env, "PATH=");
		ft_printf("path = %s\n", path);
		path_num = ft_path_num(path, ':');
		str_complete = ft_recup_path_cup(path, path_num);
		tmp_save_firth_path = str_complete[0];
		j = 0;
		i = 0;
		while (str_to_wordtab[j] != NULL)
		{
			str_complete[path_num + j] = str_to_wordtab[j];
			j++;
		}
		str_complete[path_num + j] = NULL;
		i = 0;
		str_complete[0] = tmp_save_firth_path;
		ft_printf("str 0 == %s\n", str_complete[0]);
		while (str_complete[i] != NULL)
		{
			ft_printf("str_complete de 0 :%s\n", str_complete[0]);
			ft_printf("str_complete == %s\n", str_complete[i++]);
		}
	}
	return (0);
}
