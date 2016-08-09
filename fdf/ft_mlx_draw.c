/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:44:17 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/24 17:40:06 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	h_lines(t_mlx *mlst)
{
	int		x;
	int		t;
	int		y;

	x = mlst->x1;
	while (x <= mlst->x2 && mlst->x2 - mlst->x1 != 0)
	{
		if (mlst->x1 != mlst->x2)
			y = (mlst->y1 + ((mlst->y2 - mlst->y1) * (x - mlst->x1)) /
				(mlst->x2 - mlst->x1));
		else
			y = mlst->y2;
		if (y > 0 && y < mlst->heigth - 1 && x > 0 && x < mlst->width - 1)
		{
			mlst->ptr_img2 = mlst->ptr_img + (mlst->sizel * y) + x *
				(mlst->bpp / 8);
			t = 0;
			mlst->ptr_img2[t++] = (char)(mlst->color);
			mlst->ptr_img2[t++] += (char)(mlst->color >> 8);
			mlst->ptr_img2[t] += (char)(mlst->color >> 16);
		}
		x++;
	}
}

void	v_lines(t_mlx *mlst)
{
	int		t;
	int		x;
	int		y;

	y = mlst->y1;
	while (y < mlst->y2 && mlst->y2 - mlst->y1 != 0)
	{
		if (mlst->y1 != mlst->y2)
			x = (mlst->x1 + ((mlst->x2 - mlst->x1) * (y - mlst->y1)) /
				(mlst->y2 - mlst->y1));
		else
			x = mlst->x2;
		if (y > 0 && y < mlst->heigth - 1 && x > 0 && x < mlst->width - 1)
		{
			mlst->ptr_img2 = mlst->ptr_img + (mlst->sizel * y) + x *
				(mlst->bpp / 8);
			t = 0;
			mlst->ptr_img2[t++] = (char)(mlst->color);
			mlst->ptr_img2[t++] += (char)(mlst->color >> 8);
			mlst->ptr_img2[t] += (char)(mlst->color >> 16);
		}
		y++;
	}
}

void	ft_window_to_image(t_mlx *mlst)
{
	mlst->bpp = 0;
	mlst->sizel = 0;
	mlst->endian = 0;
	mlst->win = mlx_new_window(mlst->mlx, mlst->width, mlst->heigth, "fdf");
	mlst->img = mlx_new_image(mlst->mlx, mlst->width, mlst->heigth);
	mlst->ptr_img = mlx_get_data_addr(mlst->img, &mlst->bpp,
		&mlst->sizel, &mlst->endian);
}

int		ft_key_funct(int keycode, t_mlx *mlst)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlst->mlx, mlst->img);
		mlx_destroy_window(mlst->mlx, mlst->win);
		exit(0);
	}
	else
	{
		ft_key_code(keycode, mlst);
		if (keycode == 116)
		{
			mlst->i++;
			mlst->i = mlst->i > 8 ? 0 : mlst->i;
			ft_key_code_color(mlst);
		}
		else if (keycode == 121)
		{
			mlst->i--;
			if (mlst->i < 0)
				mlst->i = 8;
			ft_key_code_color(mlst);
		}
	}
	ft_clear_n_create(mlst);
	return (1);
}

void	ft_link_adresses(t_mlx *mlst, int bt)
{
	int		i;
	int		j;

	i = -1;
	ft_link_adresses_suite(mlst, bt, &j);
	while (mlst->lst)
	{
		mlst->lst->cor = ++j;
		while (++i < (int)(mlst->lst->content_size / (sizeof(int))))
		{
			ft_set_pos(mlst, mlst->lst, 0, i);
			if (i + 1 < (int)(mlst->lst->content_size / sizeof(int)))
				ft_what_lines(mlst, i);
			ft_set_pos(mlst, mlst->lst, 1, i);
			if (mlst->lst->next != NULL)
				ft_what_lines(mlst, i);
		}
		mlst->lst = mlst->lst->next;
		i = -1;
	}
	mlst->line = bt == 0 ? j + 1 : mlst->line;
	mlx_put_image_to_window(mlst->mlx, mlst->win, mlst->img, 0, 0);
	mlx_mouse_hook(mlst->win, ft_mouse_hook, mlst);
	mlx_hook(mlst->win, 2, 1 << 9, ft_key_funct, mlst);
	mlx_loop(mlst->mlx);
}
