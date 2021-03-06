/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:26:11 by Geekette          #+#    #+#             */
/*   Updated: 2017/03/11 12:10:21 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_alloc(char *buffer)
{
	char	*ptr;

	ptr = (char *)malloc((sizeof(char) * (ft_strlen(buffer) + 1)));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, buffer);
	return (ptr);
}

int		check_eof(int count, char *buffer, int *found)
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

void	add_line(char c, char *buffer, int *count, int *found)
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
			if (check_eof(count, buffer, &found))
				return (NULL);
		}
		else
			add_line(c, buffer, &count, &found);
	}
	return (ft_alloc(buffer));
}
