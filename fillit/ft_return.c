/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:26:52 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/30 11:36:09 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_return_error(t_struct *s, t_chain *tmp)
{
	if (ft_border(s) == 0 || ft_nb_col(s) == 0 || ft_neighbor(tmp) == 0 ||
			ft_check_nb_dieze(tmp) == 0)
	{
		write(1, "error\n", 6);
		ft_free_all_list(s, tmp);
		return (0);
	}
	return (1);
}

void	ft_free_all_list(t_struct *s, t_chain *tmp)
{
	int		i;

	i = 0;
	free(s->buf);
	free(s);
	while (tmp != NULL)
	{
		while (tmp->data[i] != NULL)
		{
			free(tmp->data[i]);
			tmp->data[i] = NULL;
			i++;
		}
		free(tmp->data);
		tmp->data = NULL;
		tmp = tmp->next;
		i = 0;
	}
	free(tmp);
}

int		ft_free_all_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (1);
}
