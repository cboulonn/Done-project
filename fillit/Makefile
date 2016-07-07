# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/28 16:27:58 by cboulonn          #+#    #+#              #
#    Updated: 2016/03/28 17:37:39 by cboulonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_readncheck.c \
		   ft_custom.c \
		   ft_custom2.c \
		   ft_list_tab.c \
		   ft_pre_algo.c \
		   ft_algo_tools.c \
		   ft_algo_tools2.c \
		   ft_algo.c \
		   ft_recursive.c \
		   ft_return.c

OBJ_PATH = ./

NAME = fillit

LIB = include/libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

$(NAME): $(OBJ)
	make -C include/
	$(CC) -o $@ $(OBJ) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -I./ -o $@ -c $<

clean:
	rm -fv $(OBJ)

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
