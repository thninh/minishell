# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 17:48:36 by cprouveu          #+#    #+#              #
#    Updated: 2017/02/16 15:12:42 by Geekette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	minishell

SRCS =	minishell.c \
		get_env.c \
		path.c \
		join_path_str.c \
		check_access.c \
		fork_execve.c \

DEP =		minishell.h \
			Makefile \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(DEP)
	make -C libft
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME) -L./libft -lft

%.o: %.c $(DEP)
	gcc -g -Wall -Werror -Wextra -I. -o $@ -c $<

clean :
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: clean
