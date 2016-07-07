/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:29:42 by lbougero          #+#    #+#             */
/*   Updated: 2016/02/15 15:58:54 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_constr_square(t_struct *s, t_square *cor, int max_x, int max_y)
{
	cor->i = 0;
	cor->j = 0;
	cor->pos_x = 0;
	cor->pos_y = 0;
	while (s->map)
	{
		while (ft_square_issues(s, cor, max_x, max_y) != 1)
		{
			cor->i++;
			if (cor->i == cor->x)
			{
				cor->j++;
				if (cor->j == cor->x)
					return (0);
				else if (cor->pos_y == max_y - 1 || max_y - cor->pos_y < cor->x)
					return (1);
				cor->i = 0;
			}
		}
		if (cor->j == cor->x)
			return (0);
		else if (cor->pos_y == max_y - 1 || max_y - cor->pos_y < cor->x)
			return (1);
	}
	return (0);
}

int		ft_square_issues(t_struct *s, t_square *cor, int max_x, int max_y)
{
	if (s->map[cor->pos_y + cor->j][cor->pos_x + cor->i] == s->obs
			|| s->map[cor->pos_y + cor->j][cor->pos_x + cor->i] == '\0')
	{
		cor->i = 0;
		cor->j = 0;
		cor->pos_x++;
		if (cor->pos_x > max_x)
		{
			cor->pos_x = 0;
			cor->pos_y++;
			if (cor->pos_y == max_y)
			{
				cor->pos_y = 0;
				return (2);
			}
		}
		return (1);
	}
	return (0);
}

int		ft_begin_algo(t_struct *s)
{
	t_square	*cor;
	int			max_x;
	int			max_y;
	int			i;

	cor = (t_square *)malloc(sizeof(t_square));
	max_x = s->nb_col;
	max_y = s->nb_line;
	i = 0;
	if (max_x < max_y)
		cor->x = max_x;
	else
		cor->x = max_y;
	while (cor->x != 0)
	{
		if (ft_constr_square(s, cor, max_x, max_y) == 1)
			cor->x--;
		else
			break ;
	}
	ft_aff_win(s, cor);
	return (0);
}

int		ft_aff_win(t_struct *s, t_square *cor)
{
	int		a;
	int		b;
	int		i;

	a = 0;
	b = 0;
	i = -1;
	while (b != cor->x)
	{
		s->map[cor->pos_y + b][cor->pos_x + a] = s->full;
		a++;
		if (a >= cor->x)
		{
			a = 0;
			b++;
		}
	}
	while (s->map[++i])
	{
		ft_putstr(s->map[i]);
		ft_putstr("\n");
	}
	ft_free(s, cor);
	return (0);
}
