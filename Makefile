# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 17:48:36 by cprouveu          #+#    #+#              #
#    Updated: 2017/02/18 10:17:48 by Geekette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	minishell

SRCS =	minishell.c \
		check_if_is_builtin.c \
		echo.c \
		env.c  \
		setenv.c \
		exec.c \
		path.c \
		get_in_env.c \
		unsetenv.c \

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
