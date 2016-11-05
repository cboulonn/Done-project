/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:14:25 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/07 15:54:49 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_suite(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	b;
	int	z;

	i = 0;
	b = 0;
	while ((s[i] == c) && s[i])
		i++;
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[b] = (char *)malloc(sizeof(char) * (j - i + 1));
		z = 0;
		while (i < j)
			tab[b][z++] = s[i++];
		tab[b][z] = '\0';
		while (s[i] == c)
			i++;
		b++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len_s;

	i = 0;
	len_s = 0;
	while ((s[i] == c) && s[i])
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			len_s++;
			if (s[i - 1] == c)
				len_s--;
		}
		i++;
	}
	if (s[i - 1] == c)
		len_s--;
	if ((tab = (char**)malloc(sizeof(s) * (len_s + 2))))
		ft_suite(tab, s, c);
	if (tab)
		tab[len_s + 1] = NULL;
	return (tab);
}
