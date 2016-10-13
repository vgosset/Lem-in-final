# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgosset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 p
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 15:11:40 by vgosset           #+#    #+#              #
#    Updated: 2016/05/10 16:11:50 by vgosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = algo.c \
	  display.c \
	  main.c \
	  parsing.c \
	  tools.c \
	  tools2.c \
	  tools3.c \
	  tools4.c \
	  init_struct.c \
	  find_path.c


OBJ = $(SRC:.c=.o)

NAME = lem_in

FLAG = -Wall -Wextra -Werror

CC = gcc

LIB = Lib/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(OBJ) -I./Lib/includes -I. -L./Lib/ -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I./Lib/includes -I. -c $<

clean : 
	rm -f $(OBJ)

fclean : 
	rm -f $(OBJ) $(NAME)

re : fclean all
