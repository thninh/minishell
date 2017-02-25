/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:26:11 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/25 12:33:00 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

char	*my_alloc(char *buffer)
{
	char	*ptr;

	ptr = (char *)malloc((sizeof(char) * (ft_strlen(buffer) + 1)));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, buffer);
	return (ptr);
}

int		my_eof(int count, char *buffer, int *found)
{
	if (count == 0)
		return (1);
	else
	{
		buffer[count] = '\0';
		*found = 1;
	}
	return (0);
}

void	my_line(char c, char *buffer, int *count, int *found)
{
	if (c == '\n')
	{
		buffer[*count] = '\0';
		*found = 1;
	}
	else
	{
		buffer[*count] = c;
		*count = *count + 1;
	}
}
char	*get_next_line(const int fd)
{
	static char	buffer[BUF_SIZE];
	int			found;
	char		c;
	int			ret;
	int			count;

	count = 0;
	found = 0;
	while (found == 0)
	{
		ret = read(fd, &c, READ_SIZE);
		if (ret == 0)
	{
		if (my_eof(count, buffer, &found))
			return (NULL);
	}
	else
		my_line(c, buffer, &count, &found);
	}
	return(my_alloc(buffer));
}


// int		ft_malloc_again(char **save)
// {
// 	char	*tmp;
//
// 	if (!(tmp = ft_strnew(ft_strlen(*save))))
// 		return (0);
// 	ft_strcpy(tmp, *save);
// 	*save = NULL;
// 	if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
// 		return (0);
// 	ft_strcpy(*save, tmp);
// 	return (1);
// }
//
// int		fill_line(int j, char **save, char **line)
// {
// 	int		i;
// 	int		y;
//
// 	y = 0;
// 	i = 0;
// 	if (j != 0 || ft_strlen((*save)) != 0)
// 	{
// 		while ((*save)[i] != '\n')
// 		{
// 			(*line)[i] = (*save)[i];
// 			i++;
// 		}
// 		(*line)[i++] = '\0';
// 		if ((*save)[0] == '\n')
// 		{
// 			while ((*save)[i])
// 				(*save)[y++] = (*save)[i++];
// 			(*save)[y] = '\0';
// 			return (2);
// 		}
// 		while ((*save)[i])
// 			(*save)[y++] = (*save)[i++];
// 		(*save)[y] = '\0';
// 	}
// 	return (1);
// }
//
// int		get_next_line(int fd, char **line)
// {
// 	int			j;
// 	static char	*save;
//
// 	save = NULL;
// 	j = 0;
// 	if (fd < 0 || (!save && !(save = ft_strnew(BUFF_SIZE))))
// 		return (-1);
// 	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
// 		return (-1);
// 	while ((j = read(fd, *line, BUFF_SIZE)) > 0)
// 	{
// 		if (!(ft_malloc_again(&save)))
// 			return (-1);
// 		ft_strncat(save, *line, BUFF_SIZE);
// 		if (ft_memchr(*line, '\n', BUFF_SIZE))
// 			break ;
// 	}
// 	if ((fill_line(j, &save, &(*line))) == 2)
// 		return (1);
// 	if (ft_memcmp((*line), save, ft_strlen(*line)) == 0)
// 	{
// 		if (!(*line = ft_strdup("")))
// 			return (1);
// 		return (0);
// 	}
// 	return (1);
// }
