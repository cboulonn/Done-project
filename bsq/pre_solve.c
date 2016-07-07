/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:32:46 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/15 15:07:14 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_get_first_line(t_struct *s)
{
	int		i;
	char	**map;

	i = 0;
	while (s->buf[i] != '\n')
		i++;
	ft_get_caract(s);
	ft_get_nb_col(s);
	if (ft_get_nb_lign(s) == 1)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	map = ft_realtab(s);
	if (ft_cherror(s) == 1)
	{
		write(2, "map error\n", 10);
		ft_free(s, NULL);
	}
	else
		ft_begin_algo(s);
	return (i);
}

int		ft_get_caract(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s->line = (char *)malloc(sizeof(char) * 50);
	while (s->buf[i] != '\n')
		i++;
	while (j != i - 3)
	{
		s->line[j] = s->buf[j];
		j++;
	}
	s->l = ft_atoi(s->line);
	if (s->buf[i] == '\n')
	{
		s->full = s->buf[i - 1];
		s->obs = s->buf[i - 2];
		s->empty = s->buf[i - 3];
	}
	return (0);
}

int		ft_get_nb_col(t_struct *s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = s->buf;
	while (tmp[i] != '\n')
		tmp++;
	tmp++;
	s->nb_col = ft_linelen(tmp);
	i = s->nb_col + 1;
	return (0);
}

int		ft_get_nb_lign(t_struct *s)
{
	int		i;

	i = -1;
	s->nb_line = -1;
	while (s->buf[++i] != '\0')
	{
		if (s->buf[i] == '\n')
			s->nb_line++;
	}
	if (s->l != s->nb_line)
		return (1);
	return (0);
}

char	**ft_realtab(t_struct *s)
{
	int					i;
	int					j;
	char				*tmp;

	i = -1;
	j = 0;
	tmp = s->buf;
	s->map = (char **)malloc(sizeof(char *) * s->nb_line + 1);
	while (++i < s->nb_line)
		s->map[i] = (char *)malloc(sizeof(char) * s->nb_col + 1);
	s->map[i] = NULL;
	while (s->buf[j] != '\n')
		j++;
	j++;
	i = -1;
	while (s->map[++i])
	{
		tmp = ft_memccpy(s->map[i], &(tmp[j]), '\n', s->nb_col + 1);
		s->map[i][s->nb_col] = '\0';
		j = 0;
	}
	return (s->map);
}
