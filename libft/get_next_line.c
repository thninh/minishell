/*
** get_next_line.c for get next line in /home/wurfl_v/rendu/PSU_2013_minishell1
**
** Made by a
** Login   <wurfl_v@epitech.net>
**
** Started on  Sat Jan  4 14:55:24 2014 a
** Last update Sat Jan  4 14:55:27 2014 a
*/

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

char	*my_alloc(char *buffer)
{
  char	*ptr;

  ptr = malloc((ft_strlen(buffer) + 1) * sizeof(char));
  if (ptr == NULL)
    return (NULL);
  ft_strcpy(ptr, buffer);
  return (ptr);
}

int	my_eof(int count, char *buffer, int *found)
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
char		*get_next_line(const int fd)
{
  static char	buffer[BUF_SIZE];
  int		found;
  char		c;
  int		ret;
  int		count;

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
