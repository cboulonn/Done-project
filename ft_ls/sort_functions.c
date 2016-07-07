/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:55:13 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/20 10:07:41 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_recurs(t_lst_struct *lst, t_info *info)
{
	t_lst_struct	*tmp;
	DIR				*dir;
	struct stat		file_info;
	char			*path;

	tmp = lst;
	tmp->recurs = init_list_struct();
	while (tmp)
	{
		if (ft_d(&tmp, info, &path))
			continue;
		if (lstat(path, &file_info) == -1)
			ft_error(tmp->file->file_name);
		if (S_ISDIR(file_info.st_mode) && !S_ISLNK(file_info.st_mode))
		{
			print_path(path);
			if ((dir = opendir(path)) == NULL)
				ft_error(tmp->file->file_name);
			else
				ft_readdir(dir, info->opt, &tmp->recurs, path);
		}
		tmp = tmp->next;
	}
}

int			ft_cmp_alpha_n_time(t_lst_struct *prev, t_info *info)
{
	if (info->opt & OPT_T)
	{
		if (prev && prev->file && prev->file->time_sec > info->time_sec)
			return (-1);
		else if (prev && prev->file && prev->file->time_sec == info->time_sec)
		{
			if (prev->file->time_nsec > info->time_nsec)
				return (-1);
			else if (prev->file->time_nsec == info->time_nsec)
				return (ft_strcmp(prev->file->file_name, info->file_name));
			else
				return (1);
		}
		else
			return (1);
	}
	else if (prev && prev->file)
		return (ft_strcmp(prev->file->file_name, info->file_name));
	else
		return (-1);
}

void		sort_list(t_lst_struct **lst, t_lst_struct *act_file)
{
	t_lst_struct	*tmp;
	t_lst_struct	*prev_elem;
	t_info			*info;
	int				ret;

	tmp = NULL;
	ret = 0;
	prev_elem = *lst;
	info = act_file->file;
	while (prev_elem && (ret = ft_cmp_alpha_n_time(prev_elem, info)) < 0)
	{
		tmp = prev_elem;
		prev_elem = prev_elem->next;
	}
	act_file->next = prev_elem;
	if (tmp)
		tmp->next = act_file;
	else
		*lst = act_file;
}

void		sort_reverse(t_lst_struct **lst)
{
	t_lst_struct	*a;
	t_lst_struct	*b;
	t_lst_struct	*c;

	a = *lst;
	c = NULL;
	while (a != NULL)
	{
		b = a->next;
		a->next = c;
		c = a;
		a = b;
	}
	*lst = c;
}

void		disp_opt(t_lst_struct **lst, t_info *info, t_ls *ls)
{
	t_lst_struct	*tmp;

	tmp = *lst;
	(void)ls;
	if (!info || *lst == NULL)
		return ;
	if (info->opt & OPT_R)
		sort_reverse(&tmp);
	if (info->opt & OPT_L)
		print_opt_l(tmp, ls);
	else if (!(info->opt & OPT_L))
		print_name(tmp);
	if (info->opt & OPT_RECURS)
		ft_recurs(tmp, info);
	*lst = NULL;
}
