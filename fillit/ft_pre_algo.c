/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:49:52 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/28 17:42:41 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_swap(t_chain *tmp, t_chain *s, int save_j, int save_i)
{
	tmp->data[s->j][s->i] = '.';
	tmp->data[s->j - save_j][s->i - save_i] = '#';
}

t_chain		*ft_left_move(t_chain *tmp, int save_j, int save_i)
{
	t_chain		*s;

	s = (t_chain *)malloc(sizeof(t_chain));
	s->j = 0;
	while (tmp->data[s->j] != '\0')
	{
		s->i = 0;
		while (tmp->data[s->j][s->i])
		{
			if (tmp->data[s->j][s->i] == '#')
				ft_swap(tmp, s, save_j, save_i);
			s->i++;
		}
		s->j++;
	}
	free(s);
	return (tmp);
}

t_chain		*ft_left_premove(t_chain *tmp)
{
	int			i;
	int			j;
	int			save_i;
	int			save_j;
	t_chain		*begin_list;

	begin_list = tmp;
	while (tmp != NULL)
	{
		j = -1;
		save_j = -1;
		save_i = 0;
		while (tmp->data[++j])
		{
			i = -1;
			while (tmp->data[j][++i])
				if (tmp->data[j][i] == '#')
					ft_left_premove2(&save_j, &save_i, &j, &i);
		}
		tmp = ft_left_move(tmp, save_j, save_i);
		tmp = tmp->next;
	}
	tmp = begin_list;
	return (tmp);
}

void		ft_left_premove2(int *save_j, int *save_i, int *j, int *i)
{
	if (*save_j == -1)
	{
		*save_i = *i;
		*save_j = *j;
	}
	if (*i < *save_i)
		*save_i = *i;
}
