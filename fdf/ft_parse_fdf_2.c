/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fdf_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:26:51 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/24 17:21:22 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*ft_init_mlx(t_istruct **length, int **tab, size_t *i)
{
	t_mlx		*mlst;

	mlst = (t_mlx *)malloc(sizeof(t_mlx));
	*length = NULL;
	*length = ft_init_i_struct(*length);
	*tab = NULL;
	*i = 0;
	mlst->beg = NULL;
	mlst->lst = NULL;
	return (mlst);
}

void	ft_create_mlst(t_mlx *mlst, t_istruct *length, int *tab, char *line)
{
	tab = ft_strsplint(line, ' ');
	if (mlst->beg == NULL)
	{
		mlst->lst = ft_lstnew(tab, length->len * sizeof(int));
		mlst->beg = mlst->lst;
	}
	else
		ft_lst_push_back(&mlst->beg,
			ft_lstnew(tab, length->len * (sizeof(int))));
	free(tab);
	free(line);
}
