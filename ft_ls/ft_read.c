/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:33:06 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/25 15:00:19 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_readdir(DIR *dir, int opt, t_lst_struct **beg, char *path)
{
	struct dirent	*actual_file;
	t_lst_struct	*act_file;
	t_info			*info;
	t_ls			*ls;
	char			*name;

	act_file = NULL;
	ls = (t_ls *)malloc(sizeof(t_ls) * 1);
	init_list_ls(ls);
	while ((actual_file = readdir(dir)) != NULL)
	{
		if (!(opt & OPT_A) && actual_file->d_name[0] == '.')
			;
		else
		{
			name = ft_strsub(actual_file->d_name, 0, actual_file->d_namlen);
			info = ft_get_info(name, path, opt);
			ft_c(info, ls, act_file, beg);
		}
	}
	if (ls->button == 1)
		ft_error2(path);
	disp_opt(beg, info, ls);
	closedir(dir);
}

void	ft_readdir2(t_ls *ls, t_info *info, t_lst_struct *act_file,
	t_lst_struct **beg)
{
	ls = ft_get_length(ls, info);
	ls->total += info->block;
	act_file = init_list_struct();
	act_file->file = info;
	sort_list(beg, act_file);
}

void	ft_isdir(t_optnarg *disp_arg, t_lst_struct **t_file, t_ls *ls,
	t_lst_struct *act_file)
{
	DIR				*dir;
	struct stat		file_info;
	t_info			*info;
	t_list			*tmp;

	tmp = NULL;
	tmp = ft_places(tmp, ls, disp_arg);
	while (tmp)
	{
		dir = opendir(tmp->content);
		lstat(tmp->content, &file_info);
		if (S_ISDIR(file_info.st_mode) || (S_ISLNK(file_info.st_mode)
		&& !(disp_arg->opt & OPT_L)))
			ft_isdirsec(disp_arg, tmp->content, dir, act_file);
		else if (S_ISREG(file_info.st_mode) || S_ISLNK(file_info.st_mode))
		{
			info = ft_get_info(tmp->content, NULL, disp_arg->opt);
			ft_b(ls, t_file, act_file, info);
		}
		else
			ft_error(tmp->content);
		tmp = tmp->next;
	}
	ft_del_l_one(&tmp);
}

void	ft_readfile(t_ls *ls, t_info *info, t_lst_struct *act_file,
	t_lst_struct **t_file)
{
	ls = ft_get_length(ls, info);
	act_file = init_list_struct();
	act_file->file = info;
	sort_list(t_file, act_file);
	ls->toprint = 0;
}

void	ft_error(char *content)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(content);
	errno = 0;
	return ;
}
