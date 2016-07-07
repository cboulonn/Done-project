/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_f3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:37:24 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/16 15:22:45 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_sort_list(t_optnarg *disp_arg, DIR *dir)
{
	DIR				*dir2;
	t_info			*info;
	t_info			*info2;
	t_list			*tmp;
	t_list			*tmpb;

	tmp = disp_arg->arg;
	tmpb = tmp->next;
	while (tmp->next)
	{
		dir = opendir(tmp->content);
		dir2 = opendir(tmpb->content);
		info = ft_get_info(tmp->content, NULL, disp_arg->opt);
		info2 = ft_get_info(tmpb->content, NULL, disp_arg->opt);
		tmp = ft_sort(disp_arg, info, info2, tmp);
		tmpb = tmp->next;
	}
}

int			ft_cmp_alpha_n_time2(t_info *info, t_info *info2, t_list *tmp)
{
	if (info->opt & OPT_T)
	{
		if (tmp && info->time_sec > info2->time_sec)
			return (1);
		else if (tmp && info->time_sec == info2->time_sec)
		{
			if (info->time_nsec > info2->time_nsec)
				return (1);
			else if (info->time_nsec == info2->time_nsec)
				return (-1 * ft_strcmp(info->file_name, info2->file_name));
			else
				return (-1);
		}
		else
			return (-1);
	}
	else if (tmp)
		return (-1 * ft_strcmp(info->file_name, info2->file_name));
	else
		return (-1);
}
