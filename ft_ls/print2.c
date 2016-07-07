/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:09:12 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 16:42:31 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_total(t_ls *ls)
{
	ft_putstr("total ");
	ft_putnbr(ls->total);
	ft_putchar('\n');
}

void	print_dir_name(char *content)
{
	ft_putstr("\n");
	ft_putstr(content);
	ft_putstr(":\n");
}

void	print_path(char *path)
{
	ft_putendl("");
	ft_putstr(path);
	ft_putstr(":\n");
}

void	print_spaces(t_lst_struct *lst, t_ls *ls)
{
	ft_put_spaces_char(lst->file->right, 10);
	ft_put_spaces_int(lst->file->nb_link, ls->length_link);
	ft_put_spaces_char(lst->file->owner_name, ls->length_owner);
	ft_put_spaces_char(lst->file->grp_name, ls->length_grp);
}

void	print_link(char *link)
{
	ft_putstr(" -> ");
	ft_putstr(link);
}
