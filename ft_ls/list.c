/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:54:09 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 16:42:17 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_info			*init_list_info(t_info *lst, t_optnarg *disp_opt)
{
	lst->file_name = NULL;
	lst->owner_name = NULL;
	lst->grp_name = NULL;
	lst->last_modif = NULL;
	lst->time_sec = 0;
	lst->time_nsec = 0;
	lst->right = NULL;
	lst->size = 0;
	lst->major = 0;
	lst->minor = 0;
	lst->nb_link = 0;
	lst->opt = 0;
	if (disp_opt)
		lst->opt = disp_opt->opt;
	lst->path_lnk = NULL;
	lst->block = 0;
	lst->path = NULL;
	return (lst);
}

t_lst_struct	*init_list_struct(void)
{
	t_lst_struct *lst;

	lst = (t_lst_struct *)malloc(sizeof(t_lst_struct));
	lst->next = NULL;
	lst->file = NULL;
	lst->recurs = NULL;
	return (lst);
}

t_ls			*init_list_ls(t_ls *ls)
{
	ls->total = 0;
	ls->toprint = 1;
	ls->length_link = 0;
	ls->length_owner = 0;
	ls->length_grp = 0;
	ls->length_major = 0;
	ls->length_minor = 0;
	ls->length_size = 0;
	ls->length_time = 0;
	ls->button = 0;
	return (ls);
}
