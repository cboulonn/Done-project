#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		ptr;
	int		tab[2048];

	i = 2047;
	j = 0;
	ptr = 0;
	if (argc == 2)
	{
		while (i >= 0)
		{
			tab[i] = 0;
			i--;
		}
		while (argv[1][j])
		{
			if (argv[1][j] == '>')
				ptr++;
			else if (argv[1][j] == '<')
				ptr--;
			else if (argv[1][j] == '+')
				tab[ptr]++;
			else if (argv[1][j] == '-')
				tab[ptr]--;
			else if (argv[1][j] == '.')
				write(1, tab + ptr, 1);
			else if (argv[1][j] == '[')
			{
				if (tab[ptr] == 0)
				{
					i = 0;
					j++;
					while (argv[1][j])
					{
						if (argv[1][j] == '[')
							i++;
						else if (argv[1][j] == ']' && i == 0)
							break ;
						else if (argv[1][j] == ']')
							i--;
						j++;
					}

				}
			}
			else if (argv[1][j] == ']')
			{
				if (tab[ptr] != 0)
				{
					i = 0;
					j--;
					while (j > 0)
					{
						if (argv[1][j] == ']')
							i++;
						else if (argv[1][j] == '[' && i == 0)
							break ;
						else if (argv[1][j] == '[')
							i--;
						j--;
					}
				}
			}
			j++;
		}
		//maybe \n;
	}
	else
		write(1, "\n", 1);
	return (0);
}
