/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:40:22 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/16 18:20:17 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_del_list(t_lst_struct **file)
{
	t_lst_struct	*del_lst;
	t_lst_struct	*lst;

	if (*file != NULL)
	{
		del_lst = *file;
		while (del_lst)
		{
			free(del_lst->file);
			lst = del_lst->next;
			free(del_lst);
			del_lst = lst;
		}
	}
	*file = NULL;
}

void	ft_del_l_one(t_list **file)
{
	t_list	*del_lst;
	t_list	*lst;

	if (*file != NULL)
	{
		del_lst = *file;
		while (del_lst)
		{
			free(del_lst->content);
			lst = del_lst->next;
			free(del_lst);
			del_lst = lst;
		}
	}
	*file = NULL;
}
