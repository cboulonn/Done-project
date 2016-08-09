/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:14:24 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/24 16:13:20 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_num(char *s, int i, char c)
{
	int		j;
	int		len;
	char	*num;
	int		f_num;

	j = i;
	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	num = (char *)malloc(sizeof(char) * (len + 1));
	i = j;
	j = 0;
	while (j < len)
	{
		num[j] = s[i];
		i++;
		j++;
	}
	num[j] = '\0';
	f_num = ft_atoi(num);
	free(num);
	return (f_num);
}

void	ft_suite(int *tab, char *s, char c)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while ((s[i] == c) && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != '\0' && s[i] != c)
		{
			tab[b] = ft_num(s, i, c);
			while (s[i] != c && s[i])
				i++;
			b++;
		}
		if (s[i])
			i++;
	}
}

int		*ft_strsplint(char *s, char c)
{
	int		*tab;
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
	if ((tab = (int *)malloc(sizeof(int) * (len_s + 2))))
		ft_suite(tab, s, c);
	return (tab);
}
