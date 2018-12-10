# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 09:43:01 by agrodzin          #+#    #+#              #
#    Updated: 2018/12/02 09:43:17 by agrodzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT=libft/libft.a
PRINT=libft/printf_functions/libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror -g
SRCS= checker.c
NAME=checker
NAME2=push_swap

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft/
	make -C libft/printf_functions/
	$(CC) -c $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(PRINT)
clean:
	/bin/rm -f *.o
	make -C libft/ clean
	make -C libft/printf_functions/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)
	make -C libft/ fclean
	make -C libft/printf_functions/ fclean

re: fclean all 