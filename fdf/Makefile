# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/23 09:50:45 by cboulonn          #+#    #+#              #
#    Updated: 2016/07/25 16:44:38 by cboulonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_parse_fdf.c \
           ft_parse_suite.c \
		   ft_strsplint.c \
		   ft_mlx_draw.c \
		   ft_mlx_draw_2.c \
		   ft_mlx_draw_3.c \
		   ft_parse_fdf_2.c

OBJ_PATH = ./obj/

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror  -Iincludes -Ilibft
LDFLAGS = -lmlx -framework OpenGl -framework AppKit -Llibft -lft

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
		rm -fv $(OBJ)

fclean: clean
		make -C libft fclean
		rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
