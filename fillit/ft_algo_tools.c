/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:10:01 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/30 18:25:25 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_racine_carre(int nb)
{
	int			diviseur;

	diviseur = 1;
	if (nb > 0)
		while (diviseur * diviseur < nb)
			diviseur++;
	return (diviseur);
}

int			ft_list_size(t_chain *begin_list)
{
	t_chain		*list;

	begin_list->l_size = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		begin_list->l_size++;
	}
	if (begin_list->l_size > 26)
		return (write(1, "error\n", 6));
	return (begin_list->l_size);
}

char		**ft_free_n_create_tab(char **tab, int t_map)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (tab)
		ft_free_all_tab(tab);
	tab = (char **)malloc(sizeof(char *) * t_map + 1);
	while (++j < t_map)
		tab[j] = (char *)malloc(sizeof(char) * t_map + 1);
	tab[j] = NULL;
	j = 0;
	while (tab[j])
	{
		while (i < t_map)
			tab[j][i++] = '.';
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	return (tab);
}

t_chain		*ft_pieces_to_letters(t_chain *tmp)
{
	t_chain	*begin_list;
	int		i;
	int		j;
	int		l;

	l = 65;
	begin_list = tmp;
	while (tmp != NULL)
	{
		j = -1;
		while (tmp->data[++j])
		{
			i = -1;
			while (tmp->data[j][++i])
				if (tmp->data[j][i] == '#')
					tmp->data[j][i] = l;
		}
		l++;
		tmp = tmp->next;
	}
	tmp = begin_list;
	return (tmp);
}
