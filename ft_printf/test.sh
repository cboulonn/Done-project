make -j 8 &> /dev/null
gcc -Wall -Wextra src/ft_conv_c.c src/ft_conv_str.c src/ft_conv_str2.c src/ft_init.c src/ft_instr.c src/ft_parse.c src/ft_printf.c src/ft_put_int.c src/ft_put_int_2.c src/ft_treat_int.c src/ft_wildchar.c src/ft_wildstr.c  src/ft_sprintf.c src/main.c libftprintf.a
./a.out &> test_ft_printf
gcc src/main_printf.c libftprintf.a
./a.out &> test_printf
make fclean -j 8 &> /dev/null
diff -y test_ft_printf test_printf
rm a.out test_ft_printf test_printf
