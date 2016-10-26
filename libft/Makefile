# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 15:37:02 by cboulonn          #+#    #+#              #
#    Updated: 2016/10/26 16:44:55 by cboulonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH_PRINTF =	srcs/ft_printf/

SRC_NAME_PRINTF =	ft_conv_c.c \
					ft_conv_str.c \
					ft_conv_str2.c \
					ft_init.c \
					ft_instr.c \
					ft_parse.c \
					ft_printf.c \
					ft_put_int.c \
					ft_put_int_2.c \
					ft_treat_int.c \
					ft_wildchar.c \
					ft_wildstr.c \
					ft_sprintf.c \
					ft_dprintf.c

SRC_PATH_LIBFT =	srcs/

SRC_NAME_LIBFT = 	ft_atoi.c \
           			ft_bzero.c \
		   			ft_isalnum.c \
		   			ft_isalpha.c \
		   			ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar.c \
					ft_putchar_fd.c  \
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
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_strjoin_n_free.c \
					ft_linelen.c \
					ft_strndup.c \
					ft_iterative_power.c \
					ft_lst_push_back.c \
					get_next_line.c \
					ft_swap_int.c \
					ft_swap_float.c \
					ft_strnjoin.c \
					ft_long_itoa.c \
					ft_ulong_itoa_base.c \
					ft_itoa_base.c


OBJ_NAME_LIBFT = $(SRC_NAME_LIBFT:.c=.o)
OBJ_NAME_PRINTF = $(SRC_NAME_PRINTF:.c=.o)

OBJ_PATH = ./obj/
LIBFT_PATH = includes
PRINTF_PATH = includes

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC_LIBFT = $(addprefix $(SRC_PATH_LIBFT), $(SRC_NAME_LIBFT))
OBJ_LIBFT = $(addprefix $(OBJ_PATH), $(OBJ_NAME_LIBFT))
OBJ_PRINTF = $(addprefix $(OBJ_PATH), $(OBJ_NAME_PRINTF))
OBJ = $(OBJ_LIBFT) $(OBJ_PRINTF)
SRC_PRINTF = $(addprefix $(SRC_PATH_PRINTF), $(SRC_NAME_PRINTF))
LIBFT = $(addprefix -I,$(LIBFT_PATH))
PRINTF = $(addprefix -I,$(PRINTF_PATH))

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH_LIBFT)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIBFT) -o $@ -c $<

$(OBJ_PATH)%.o:$(SRC_PATH_PRINTF)%.c
	$(CC) $(CFLAGS) $(LIBFT) -o $@ -c $<

clean:
		rm -rfv $(OBJ_PATH)

fclean: clean
		rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
