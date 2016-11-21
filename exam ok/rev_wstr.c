#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	rev_wstr(char *str, int mot)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(str[i] != '\0')
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i])
			return ;
		j = i;
		while(str[i] && (str[i] != ' ' && str[i] != '\t'))	
			i++;
		rev_wstr(&str[i], 0);
		write(1, &str[j], i - j);
		if (!mot)
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1], 1);
	ft_putchar('\n');
	return (0);
}
