//Version GAUTIER


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 3

typedef struct	s_lst
{
	char			*content;
	int				fd;
	struct s_lst	*next;
}				t_lst;

void			ft_lst_push_back_gnl(t_lst **begin_list, int fd);
int				get_next_line(int const fd, char **line);

#endif
