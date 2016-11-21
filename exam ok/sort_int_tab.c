void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				t;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			t = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = t;
			i = 0;
		}
	}
}