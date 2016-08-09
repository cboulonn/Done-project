/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:48 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/24 17:38:42 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pos(t_mlx *mlst, t_list *lst, int button, int i)
{
	int	*tab2;
	int	*tab;
	int	j;

	tab2 = NULL;
	tab = NULL;
	tab = lst->content;
	j = lst->cor;
	if (button == 0)
	{
		if (i + 1 < (int)(lst->content_size / sizeof(int)))
			ft_cor_1(mlst, i, j, tab);
	}
	else if (lst->next != NULL)
	{
		tab2 = lst->next->content;
		ft_cor_2(mlst, i, j, tab);
		ft_cor_2_bis(mlst, i, j, tab2);
	}
	if (mlst->rev == 1)
	{
		ft_swap_int(&mlst->x1, &mlst->y1);
		ft_swap_int(&mlst->x2, &mlst->y2);
	}
}

void	ft_what_lines(t_mlx *mlst, int i)
{
	int		*tab;
	int		*tab2;

	tab = mlst->lst->content;
	tab2 = mlst->lst->next ? mlst->lst->next->content : NULL;
	if (!mlst->bt_d || (tab[i] > 0 || (tab2 && tab2[i] > 0)) ||
	(i + 1 < (int)(mlst->lst->content_size / (sizeof(int)) && tab[i + 1] > 0)))
	{
		if (ABS(mlst->x2 - mlst->x1) > ABS(mlst->y2 - mlst->y1))
		{
			if (mlst->x2 - mlst->x1 <= 0)
			{
				ft_swap_int(&mlst->x1, &mlst->x2);
				ft_swap_int(&mlst->y1, &mlst->y2);
			}
			h_lines(mlst);
		}
		else if (mlst->y2 - mlst->y1 <= 0)
		{
			ft_swap_int(&mlst->x1, &mlst->x2);
			ft_swap_int(&mlst->y1, &mlst->y2);
		}
		v_lines(mlst);
	}
}

void	ft_clear_n_create(t_mlx *mlst)
{
	mlx_clear_window(mlst->mlx, mlst->win);
	mlx_destroy_image(mlst->mlx, mlst->img);
	mlst->img = mlx_new_image(mlst->mlx, mlst->width, mlst->heigth);
	mlst->ptr_img = mlx_get_data_addr(mlst->img, &mlst->bpp,
		&mlst->sizel, &mlst->endian);
	mlst->lst = mlst->beg;
	ft_link_adresses(mlst, 1);
}

void	ft_key_code(int keycode, t_mlx *mlst)
{
	if (keycode == 67)
		mlst->alt = mlst->alt + 0.1;
	else if (keycode == 75)
		mlst->alt = mlst->alt - 0.1;
	else if (keycode == 126)
		mlst->t_w = mlst->t_w - 5;
	else if (keycode == 125)
		mlst->t_w = mlst->t_w + 5;
	else if (keycode == 123)
		mlst->t_h = mlst->t_h - 5;
	else if (keycode == 124)
		mlst->t_h = mlst->t_h + 5;
	else if (keycode == 2)
	{
		if (mlst->bt_d == 0)
			mlst->bt_d = 1;
		else
			mlst->bt_d = 0;
	}
	ft_keycode_suite(keycode, mlst);
}

void	ft_key_code_color(t_mlx *mlst)
{
	if (mlst->i == 0)
		mlst->color = 0xFFFFFF;
	if (mlst->i == 1)
		mlst->color = 0xFF0000;
	if (mlst->i == 2)
		mlst->color = 0xFF4500;
	if (mlst->i == 3)
		mlst->color = 0xFFFF00;
	if (mlst->i == 4)
		mlst->color = 0x32CD32;
	if (mlst->i == 5)
		mlst->color = 0x1E90FF;
	if (mlst->i == 6)
		mlst->color = 0x0000FF;
	if (mlst->i == 7)
		mlst->color = 0x4B0082;
	if (mlst->i == 8)
		mlst->color = 0x2F4F4F;
}
