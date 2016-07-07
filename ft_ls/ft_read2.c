/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:35:21 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/20 09:26:32 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_c(t_info *info, t_ls *ls, t_lst_struct *act_file, t_lst_struct **beg)
{
	if (info != NULL)
		ft_readdir2(ls, info, act_file, beg);
	else
		ls->button = 1;
}

void	ft_isdirsec(t_optnarg *disp_arg, char *name, DIR *dir,
	t_lst_struct *act_file)
{
	if (dir != NULL)
		ft_isdir3(disp_arg, name, dir, act_file);
	else
		ft_error(name);
}

void	ft_isdir3(t_optnarg *disp_arg, char *name, DIR *dir,
	t_lst_struct *act_file)
{
	if (disp_arg->nb_arg > 1 ||
		(disp_arg->nb_arg >= 1 && disp_arg->opt == 0) ||
		(disp_arg->button == 1))
		print_dir_name(name);
	ft_readdir(dir, disp_arg->opt, &act_file, name);
}

t_list	*ft_places(t_list *tmp, t_ls *ls, t_optnarg *disp_arg)
{
	DIR		*dir;

	init_list_ls(ls);
	dir = NULL;
	ft_sort_list(disp_arg, dir);
	if (disp_arg->opt & OPT_R)
		sort_reverse_list(&disp_arg->arg);
	ft_sort_arg_rep(disp_arg, dir);
	tmp = disp_arg->arg;
	return (tmp);
}

void	ft_b(t_ls *ls, t_lst_struct **t_file, t_lst_struct *act_file,
	t_info *info)
{
	if (info != NULL)
	{
		ft_readfile(ls, info, act_file, t_file);
		disp_opt(t_file, info, ls);
	}
}
