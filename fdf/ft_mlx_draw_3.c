/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 10:55:51 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/25 14:54:08 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cor_1(t_mlx *mlst, int i, int j, int *tab)
{
	mlst->x1 = (i - j) * ((64 * mlst->zoom)) +
		((mlst->t_h));
	mlst->y1 = ((i + j) * ((32 * mlst->zoom)) - (mlst->alt * tab[i]) +
		((mlst->t_w)));
	mlst->x2 = ((i + 1) - j) * ((64 * mlst->zoom)) +
		((mlst->t_h));
	mlst->y2 = (((i + 1) + j) * ((32 * mlst->zoom)) -
		(mlst->alt * tab[i + 1]) + ((mlst->t_w)));
}

void	ft_cor_2(t_mlx *mlst, int i, int j, int *tab)
{
	mlst->x1 = (i - j) * ((64 * mlst->zoom)) +
		((mlst->t_h));
	mlst->y1 = ((i + j) * ((32 * mlst->zoom)) - (mlst->alt * tab[i]) +
		((mlst->t_w)));
}

void	ft_cor_2_bis(t_mlx *mlst, int i, int j, int *tab2)
{
	mlst->x2 = (i - (j + 1)) * ((64 * mlst->zoom)) +
		((mlst->t_h));
	mlst->y2 = ((i + (j + 1)) * ((32 * mlst->zoom)) - (mlst->alt * tab2[i]) +
		((mlst->t_w)));
}

void	ft_keycode_suite(int keycode, t_mlx *mlst)
{
	if (keycode == 78)
	{
		mlst->zoom = mlst->zoom - 0.01;
		mlst->t_h = mlst->t_h + 3;
		mlst->t_w = mlst->t_w + 7;
	}
	else if (keycode == 69)
	{
		mlst->zoom = mlst->zoom + 0.01;
		mlst->t_h = mlst->t_h - 3;
		mlst->t_w = mlst->t_w - 7;
	}
	else if (keycode == 15)
	{
		if (mlst->rev == 0)
			mlst->rev = 1;
		else
			mlst->rev = 0;
	}
	else if (keycode == 8)
		mlst->alt = 2;
}

void	ft_link_adresses_suite(t_mlx *mlst, int bt, int *j)
{
	*j = -1;
	if (bt == 0)
	{
		mlst->i = 0;
		mlst->color = 0xFFFFFF;
		mlst->rev = 0;
		mlst->bt_d = 0;
		mlst->dpl1 = 1;
		mlst->dpl2 = 1;
		mlst->t_h = 800 -
			((mlst->line - (mlst->beg->content_size / 4)) *
			((int)(32 * mlst->zoom) / 2) / 2);
		mlst->t_w = 555 -
			((mlst->line + (mlst->beg->content_size / 4)) *
			((int)(64 * mlst->zoom) / 2) / 2);
		mlst->heigth = 1080;
		mlst->width = 1920;
		mlst->alt = 2;
		mlst->zoom = 0.5;
		mlst->mlx = mlx_init();
		ft_window_to_image(mlst);
	}
}
