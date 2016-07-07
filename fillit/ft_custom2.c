/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:22:44 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/30 11:52:05 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_neighbor2(t_chain *tmp, int c_dieze)
{
	int		j;
	int		i;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (tmp->data[j][i] == '#')
			{
				if (j < 3 && tmp->data[j + 1][i] == '#')
					c_dieze++;
				if (j > 0 && tmp->data[j - 1][i] == '#')
					c_dieze++;
				if (i < 3 && tmp->data[j][i + 1] == '#')
					c_dieze++;
				if (i > 0 && tmp->data[j][i - 1] == '#')
					c_dieze++;
			}
	}
	return (c_dieze);
}

t_chain		*ft_custom_house2(t_chain *tmp)
{
	while (tmp)
	{
		ft_free_all_tab(tmp->data);
		free(tmp->next);
		tmp = tmp->next;
	}
	free(tmp);
	return (tmp);
}

int			ft_check_nb_dieze(t_chain *tetriste)
{
	int		c_dieze;
	int		i;
	int		j;

	while (tetriste != NULL)
	{
		c_dieze = 0;
		j = 0;
		while (tetriste->data[j])
		{
			i = 0;
			while (tetriste->data[j][i])
			{
				if (tetriste->data[j][i] == '#')
					c_dieze++;
				i++;
			}
			j++;
		}
		if (c_dieze > 4)
			return (0);
		tetriste = tetriste->next;
	}
	return (1);
}
