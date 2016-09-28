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

vpath %.c ./ ./printf/

SRC = ft_atoi.c \
	ft_puttab.c	\
	ft_bzero.c \
	ft_stric.c \
  ft_isalnum.c \
  ft_isalpha.c \
  ft_isascii.c \
  ft_isdigit.c \
  ft_memccpy.c \
  ft_memchr.c \
  ft_memcmp.c \
  ft_memcpy.c \
  ft_memmove.c \
  ft_memset.c \
  ft_putchar.c \
  ft_putchar_fd.c \
  ft_putendl.c \
  ft_putendl_fd.c \
  ft_putnbr.c \
  ft_putnbr_fd.c \
  ft_putstr.c \
  ft_putstr_fd.c \
  ft_strcat.c \
  ft_strchr.c \
  ft_strclr.c \
  ft_strcmp.c \
  ft_strcpy.c \
  ft_strdup.c \
  ft_strequ.c \
  ft_striter.c \
  ft_striteri.c \
  ft_strlen.c \
  ft_strmap.c \
  ft_strmapi.c \
  ft_strncpy.c \
  ft_strnequ.c \
  ft_strnstr.c \
  ft_strrchr.c \
  ft_strstr.c \
  ft_tolower.c \
  ft_toupper.c \
  ft_strncat.c \
  ft_memalloc.c \
  ft_memdel.c \
  ft_strnew.c \
  ft_strdel.c \
  ft_strsub.c \
  ft_strjoin.c \
  ft_strtrim.c \
  ft_strsplit.c \
  ft_isprint.c \
  ft_strncmp.c \
  ft_itoa.c \
  ft_strlcat.c \
  ft_lstnew.c \
  ft_lstadd.c \
  ft_lstiter.c \
  ft_lstmap.c \
  ft_lstdelone.c \
  ft_lstdel.c \
  ft_isspace.c \
  ft_strwords.c \
  ft_count.c \
  ft_count_long.c \
  ft_count_wchar.c \
  ft_itoa_base.c \
  ft_power.c \
  ft_printf.c \
  ft_putint.c \
  ft_putwchar.c \
  ft_putwstr.c \
  ft_words.c \
  check_display_block_d.c \
  check_display_block_o.c \
  check_display_block_p.c \
  check_display_block_u.c \
  check_display_block_x.c \
  check_format.c \
  check_format_2.c \
  display_block.c \
  set_c.c \
  set_d.c \
  set_d_norm.c \
  set_format.c \
  set_hex.c \
  set_octal.c \
  set_p.c \
  set_s.c \
  set_tag.c \
  set_u.c \
  set_wchar_s.c \
  tools.c \
  tools2.c \
  ft_count_base.c \
  get_next_line.c


OBJ = $(SRC:.c=.o)

NAME = libft.a

FLAG = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I./includes -c $<

clean : 
	rm -f $(OBJ)

fclean : 
	rm -f $(OBJ) $(NAME)

re : fclean all
