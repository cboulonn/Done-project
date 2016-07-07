/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:36:36 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/28 17:29:16 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_cpytab(char **save_map)
{
	int		i;
	char	**cpy;

	i = 0;
	while (save_map[i])
		i++;
	cpy = (char **)malloc(sizeof(char *) * (i + 1));
	cpy[i] = NULL;
	while ((--i != -1))
		if (save_map[i])
			cpy[i] = ft_strdup(save_map[i]);
	return (cpy);
}

void		ft_puttab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}

char		ft_find_char(t_chain *tmp)
{
	int i;

	i = 0;
	while (tmp->data[0][i] == '.')
		i++;
	return (tmp->data[0][i]);
}

void		ft_cpy_letters(t_chain *tmp, char **save_map, char **map)
{
	char	c;
	int		x;
	int		y;

	x = 0;
	y = 0;
	c = ft_find_char(tmp);
	while (save_map[y])
	{
		x = 0;
		while (save_map[y][x] != '\0')
		{
			if (save_map[y][x] == c)
				map[y][x] = c;
			x++;
		}
		y++;
	}
}
