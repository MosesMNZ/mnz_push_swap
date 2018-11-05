# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 16:17:11 by mmuamba           #+#    #+#              #
#    Updated: 2018/09/04 08:49:12 by mmuamba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER =	libft.h

NAME = 		libft.a

SRC = 	*.c	

OBJS = 	*.o

FLAGS = 	-Wall -Wextra -Werror

CC = 		gcc

all : 	$(NAME)
	
$(NAME):
		$(CC) $(FLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean: 
		rm -rf $(OBJS)
fclean:	clean
		rm -f $(NAME)

re: 	fclean all
