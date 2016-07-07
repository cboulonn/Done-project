/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:29:26 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/30 18:46:34 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_1(char **map, char **cpy, t_chain *tmp)
{
	ft_cpy_letters(tmp, cpy, map);
	ft_free_all_tab(cpy);
	return (1);
}

int		ft_recursive(char **map, char **save_map, t_chain *first)
{
	t_chain	*tmp;
	char	**cpy;

	tmp = first;
	cpy = NULL;
	while (tmp != NULL && ft_find_tetris(save_map, tmp) == 0)
		tmp = tmp->next;
	while (tmp)
	{
		while (tmp != NULL && ft_find_tetris(save_map, tmp) == 0 &&
				!(tmp->boul = 0))
			tmp = tmp->next;
		while (tmp && (cpy = ft_place_the_tetris(save_map, tmp, first)) == NULL
				&& !(tmp->boul = 0) &&
				(tmp = tmp->next))
			while (tmp != NULL && ft_find_tetris(save_map, tmp) == 0)
				tmp = tmp->next;
		if (tmp && (ft_recursive(map, cpy, first) == 1))
			return (ft_1(map, cpy, tmp));
		else if (!tmp || !ft_free_all_tab(cpy))
			return (!(tmp = first));
	}
	return (1);
}
