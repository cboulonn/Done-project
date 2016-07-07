# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 14:35:17 by cboulonn          #+#    #+#              #
#    Updated: 2016/02/15 15:04:41 by cboulonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all: $(NAME)

$(NAME): algo_bsqtest2.o ft_print.o ft_strjoin_n_free.o pre_solve.o print2.o retandstock.o
	gcc -Wall -Wextra -Werror -o $(NAME) algo_bsqtest2.o ft_print.o ft_strjoin_n_free.o pre_solve.o print2.o retandstock.o

algo_bsqtest2.o :
	gcc -c -Wall -Wextra -Werror algo_bsqtest2.c

ft_print.o :
	gcc -c -Wall -Wextra -Werror ft_print.c

ft_strjoin_n_free.o :
	gcc -c -Wall -Wextra -Werror ft_strjoin_n_free.c

pre_solve.o :
	gcc -c -Wall -Wextra -Werror pre_solve.c

print2.o :
	gcc -c -Wall -Wextra -Werror print2.c

retandstock.o :
	gcc -c -Wall -Wextra -Werror retandstock.c

clean:
	/bin/rm -f algo_bsqtest2.o ft_print.o ft_strjoin_n_free.o pre_solve.o print2.o retandstock.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
