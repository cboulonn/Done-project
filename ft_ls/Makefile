# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/23 09:50:45 by cboulonn          #+#    #+#              #
#    Updated: 2016/06/20 10:25:05 by cboulonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_read.c \
		   ft_read2.c \
		   get_arg_opt.c \
		   get_info.c \
		   get_info2.c \
		   get_info3.c \
		   list.c \
		   print.c \
		   print2.c \
		   sort_functions.c \
		   sort_f2.c \
		   sort_f3.c \
		   ft_start.c \
		   ft_start2.c \
		   list_del.c \
		   sort_arg_rep.c \
		   get_length.c

OBJ_PATH = ./obj/

NAME = ft_ls

CC = gcc
CFLAGS = -Werror -Wall -Wextra -Iincludes -Ilibft
LDFLAGS = -Llibft -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		$(CC) -o $@ $(OBJ) $(LDFLAGS)

libft:
	@make -C libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rfv $(OBJ_PATH)

fclean: clean
		make -C libft fclean
		rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
