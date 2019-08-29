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
SRCS=checker.c
SRCS2=push_swap.c\
merge_sort.c\
simple_sort.c\
b_to_a.c\
split.c\
bigger_sort.c
SRCS_COMBINE=utils.c\
utils2.c\
utils3.c\
utils_4.c\
init.c\
check_params.c\
call_exec.c\
exec_swap.c
SRCS_TEST=push_swap.c
NAME=checker
NAME2=push_swap
NAME3=test
OBJ=$(SRCS:%.c=%.o)
OBJ2=$(SRCS2:%.c=%.o)
OBJCOMBINE=$(SRCS_COMBINE:%.c=%.o)
all: $(OBJ)

$(OBJ) : $(SRCS)
	make -C libft/
	make -C libft/printf_functions/
	$(CC) $(CFLAGS) -c $(SRCS_COMBINE) $(SRCS) $(SRCS2)
	$(CC) $(OBJCOMBINE) $(OBJ) $(LIBFT) $(PRINT) -o $(NAME)
	$(CC) $(OBJCOMBINE) $(OBJ2) $(LIBFT) $(PRINT) -o $(NAME2)

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