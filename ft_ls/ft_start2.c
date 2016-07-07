/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 15:52:33 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/20 10:03:46 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_free(t_list *tmp)
{
	ft_error(tmp->content);
	if (tmp->content)
		ft_memdel(&tmp->content);
	free(tmp);
}

int		ft_return(t_optnarg *lst_arg)
{
	if (lst_arg->nb_arg == 0)
		return (-1);
	else
		return (1);
}

int		ft_parse_error(t_optnarg *lst_arg, int i)
{
	t_list			*tmp;
	t_list			*prev;
	struct stat		file_info;

	prev = NULL;
	tmp = lst_arg->arg;
	while (tmp)
		if (lstat(tmp->content, &file_info) == -1)
		{
			if (prev)
				prev->next = tmp->next;
			else
				lst_arg->arg = tmp->next;
			ft_free(tmp);
			tmp = prev ? prev : lst_arg->arg;
			lst_arg->nb_arg = lst_arg->nb_arg - 1;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	return (i = ft_return(lst_arg));
}

int		ft_d(t_lst_struct **tmp, t_info *info, char **path)
{
	if ((info->opt & OPT_A) && (*tmp)->file && (*tmp)->file->file_name)
	{
		if ((*tmp)->file->file_name[0] == '.' &&
		(*tmp)->file->file_name[1] == '\0' && (((*tmp) = (*tmp)->next) || 1))
			return (1);
	}
	if ((*tmp)->file && (*tmp)->file->file_name &&
	ft_strcmp((*tmp)->file->file_name, "..") != 0)
		(*path) = ft_strjoin(info->path, (*tmp)->file->file_name);
	else if (((*tmp) = (*tmp)->next) || 1)
		return (1);
	return (0);
}
