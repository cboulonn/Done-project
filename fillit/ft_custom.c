/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:47:00 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/30 11:50:23 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nb_lign(t_struct *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = s->buf;
	while (tmp[i] != '\0')
	{
		while (tmp[i] != '\n')
			i++;
		i++;
		j++;
		if (tmp[i] == '\n')
		{
			if (j != 4)
				return (0);
			j = 0;
			i++;
		}
	}
	if (j != 4 && tmp[i] == '\0')
		return (0);
	return (1);
}

int		ft_nb_col(t_struct *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = s->buf;
	while (tmp && tmp[i] != '\0')
	{
		while (tmp[i] != '\0' && tmp[i] != '\n')
			i++;
		i++;
		j++;
		if ((i - j) % 4 != 0)
			return (0);
	}
	if (ft_nb_lign(s) == 0)
		return (0);
	return (1);
}

int		ft_border(t_struct *s)
{
	int		i;

	i = 0;
	while (s->buf[i] != '\0')
	{
		if (s->buf[i] != '#' && s->buf[i] != '\n'
				&& s->buf[i] != '\0' && s->buf[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_neighbor(t_chain *tetriste)
{
	int		c_dieze;

	c_dieze = 0;
	while (tetriste != NULL)
	{
		c_dieze = ft_neighbor2(tetriste, c_dieze);
		if (c_dieze < 6)
			return (0);
		tetriste = tetriste->next;
		c_dieze = 0;
	}
	return (1);
}

int		ft_custom_house(t_struct *s)
{
	t_chain		*tmp;
	t_chain		*tetriste;
	int			i;

	i = 0;
	tmp = NULL;
	tetriste = NULL;
	tetriste = (t_chain *)malloc(sizeof(t_chain));
	tetriste = chainlisttab(s, tmp);
	if (ft_return_error(s, tetriste) == 0)
		exit(0);
	tmp = tetriste;
	tmp = ft_left_premove(tetriste);
	ft_algo(tmp);
	if (tetriste != NULL)
		free(tetriste);
	tetriste = NULL;
	if (tmp != NULL)
		ft_custom_house2(tmp);
	tmp = NULL;
	return (0);
}
