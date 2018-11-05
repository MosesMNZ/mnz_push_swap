# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 10:05:19 by mmuamba           #+#    #+#              #
#    Updated: 2018/09/12 14:58:15 by mmuamba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	checker
NAME2	=	push_swap
CC		=	gcc -o
FLAGS	=	-Wall -Wextra -Werror
INC		= 	-I ./includes/
LIB		= 	./libft/
SRC1 	= 	./srcs/algo.c ./srcs/moving_2.c ./srcs/ret_do.c\
			./srcs/moving_1.c ./srcs/printer.c ./srcs/rotation_1.c\
			./srcs/initializer.c ./srcs/rotation_2.c ./srcs/get_op.c\
			./srcs/pushing_swaping.c ./srcs/create_check_stack.c\
			./srcs/put_order.c ./srcs/updating.c ./srcs/checker.c
SRC2 	= 	./srcs/algo.c ./srcs/moving_2.c ./srcs/ret_do.c\
			./srcs/moving_1.c ./srcs/printer.c ./srcs/rotation_1.c\
			./srcs/initializer.c ./srcs/rotation_2.c ./srcs/get_op.c\
			./srcs/pushing_swaping.c ./srcs/create_check_stack.c\
			./srcs/put_order.c ./srcs/updating.c ./srcs/push_swap.c
RM		= 	rm -rf

$(NAME1):
	@make -C $(LIB)
	@$(CC) $(NAME1) $(FLAGS) $(SRC1) $(INC) -L libft/ -lft
	@echo "\x1B[32mChecker compiled successfully\x1B[3m"

$(NAME2):
	@make -C $(LIB)
	@$(CC) $(NAME2) $(FLAGS) $(SRC2) $(INC) -L libft/ -lft
	@echo "\x1B[32mPush_swap compiled successfully\x1B[3m"

all: $(NAME1) $(NAME2)
clean:
	@make clean -C $(LIB)
fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME1) $(NAME2)
re: fclean all


