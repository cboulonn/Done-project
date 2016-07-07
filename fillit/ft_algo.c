/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:49:39 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/30 18:50:29 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_put_the_letter(char **cpy, t_chain *tmp)
{
	int		i;
	int		j;

	j = 0;
	while (tmp->data[j])
	{
		i = 0;
		while (tmp->data[j][i])
		{
			if (tmp->data[j][i] != '.' &&
				cpy[tmp->pos_y + j][tmp->pos_x + i] == '.')
				cpy[tmp->pos_y + j][tmp->pos_x + i] = tmp->data[j][i];
			i++;
		}
		j++;
	}
	return (cpy);
}

char	**ft_sol_place(char **cpy, t_chain *tmp, t_chain *first)
{
	int		i;
	int		j;
	int		c;

	j = -1;
	c = 0;
	while (tmp->data[++j])
	{
		i = -1;
		while (tmp->data[j][++i])
		{
			if (tmp->pos_y + j < first->t_map && tmp->data[j][i] != '.' &&
					cpy[tmp->pos_y + j][tmp->pos_x + i] != '.')
				return (NULL);
			else if (tmp->pos_y + j < first->t_map && tmp->data[j][i] != '.' &&
					cpy[tmp->pos_y + j][tmp->pos_x + i] == '.')
				c++;
			if (c == 4)
			{
				cpy = ft_put_the_letter(cpy, tmp);
				return (cpy);
			}
		}
	}
	return (NULL);
}

char	**ft_place_the_tetris(char **save_map, t_chain *tmp, t_chain *first)
{
	char **cpy;

	cpy = ft_cpytab(save_map);
	if (tmp->boul == 0)
	{
		tmp->pos_x = 0;
		tmp->pos_y = 0;
		tmp->boul = 1;
	}
	else
		tmp->pos_x++;
	while (tmp->pos_y < first->t_map)
	{
		if (tmp->pos_x == first->t_map)
		{
			tmp->pos_x = 0;
			tmp->pos_y++;
		}
		if ((ft_sol_place(cpy, tmp, first)) != NULL)
			return (cpy);
		else
			tmp->pos_x++;
	}
	ft_free_all_tab(cpy);
	return (NULL);
}

int		ft_find_tetris(char **save_map, t_chain *tmp)
{
	int		i;
	int		j;
	int		l;

	if (tmp == NULL)
		return (1);
	l = ft_find_char(tmp);
	j = 0;
	while (save_map[j])
	{
		i = 0;
		while (save_map[j][i])
		{
			if (save_map[j][i] == l)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_algo(t_chain *tmp)
{
	int		i;
	int		j;
	char	**map;
	char	**save_map;

	tmp->t_map = 0;
	tmp->boul = 0;
	i = -1;
	j = 0;
	map = NULL;
	tmp->t_map = ft_racine_carre(4 * ft_list_size(tmp));
	map = ft_free_n_create_tab(map, tmp->t_map);
	tmp = ft_pieces_to_letters(tmp);
	save_map = ft_cpytab(map);
	while (ft_recursive(map, save_map, tmp) != 1)
	{
		tmp->t_map++;
		map = ft_free_n_create_tab(map, tmp->t_map);
		ft_free_all_tab(save_map);
		save_map = ft_cpytab(map);
	}
	ft_free_all_tab(save_map);
	while (map[++i])
		ft_putendl(map[i]);
	return (!(ft_free_all_tab(map)));
}
