/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:16:35 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/25 14:53:13 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_istruct	*ft_init_i_struct(t_istruct *length)
{
	length = (t_istruct *)malloc(sizeof(t_istruct));
	length->check = 0;
	length->len = 0;
	length->save = 0;
	length->res = 0;
	return (length);
}

int			ft_mouse_hook(int button, int x, int y, t_mlx *mlst)
{
	(void)button;
	mlst->t_h = x - ((mlst->line - (mlst->beg->content_size / 4))
		* ((int)(64 * mlst->zoom) / 2) / 2);
	mlst->t_w = y - ((mlst->line + (mlst->beg->content_size / 4))
		* ((int)(32 * mlst->zoom) / 2) / 2);
	ft_clear_n_create(mlst);
	return (1);
}
