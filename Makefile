# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 17:48:36 by cprouveu          #+#    #+#              #
#    Updated: 2017/02/24 10:04:56 by Geekette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	minishell

SRCS =	minishell.c \
		ft_check_command.c \
		ft_clean_str.c \
		ft_do_execute.c \
		ft_get_env.c \
		ft_read.c \
		ft_command.c \
		builtin_setenv.c \
		builtin_unsetenv.c \
		builtin_env.c \
		builtin_echo.c \
		builtin_cd.c \

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
