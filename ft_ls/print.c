/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:17:24 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 12:15:21 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_put_spaces_int(int info, int len_max)
{
	int		i;
	int		act_len;

	i = 0;
	act_len = 0;
	act_len = ft_strlen(ft_itoa(info));
	i = act_len;
	if (i == 1)
		i = 2;
	if (act_len < len_max)
	{
		while (i < len_max)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(info);
		ft_putstr(" ");
	}
	else
	{
		ft_putnbr(info);
		ft_putstr(" ");
	}
}

void	ft_put_spaces_major(int info, int len_max)
{
	int		i;
	int		act_len;

	i = 0;
	act_len = 0;
	act_len = ft_strlen(ft_itoa(info));
	i = act_len;
	if (i == 1)
		i = 2;
	if (act_len < len_max)
	{
		while (i < len_max)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(info);
		ft_putstr(", ");
	}
	else
	{
		ft_putnbr(info);
		ft_putstr(", ");
	}
}

void	ft_put_spaces_char(char *info, int len_max)
{
	int		i;
	int		act_len;

	i = 0;
	act_len = 0;
	act_len = ft_strlen(info);
	i = act_len;
	if (act_len < len_max)
	{
		ft_putstr(info);
		while (i < len_max)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putstr("  ");
	}
	else
	{
		ft_putstr(info);
		ft_putstr("  ");
	}
}

void	print_opt_l(t_lst_struct *lst, t_ls *ls)
{
	if (ls->toprint)
		print_total(ls);
	while (lst)
	{
		if (!lst->file && (lst = lst->next) + 1)
			continue ;
		print_spaces(lst, ls);
		if ((ft_strchr(lst->file->right, 'c') != NULL)
		|| (ft_strchr(lst->file->right, 'b') != NULL))
		{
			ft_put_spaces_major(lst->file->major, ls->length_major);
			ft_put_spaces_int(lst->file->minor, ls->length_minor);
		}
		else
			ft_put_spaces_int(lst->file->size, ls->length_size);
		ft_put_spaces_char(lst->file->last_modif, ls->length_time);
		ft_putstr(lst->file->file_name);
		if (lst->file->path_lnk != NULL)
			print_link(lst->file->path_lnk);
		ft_putstr("\n");
		lst = lst->next;
	}
	ft_del_list(&lst);
}

void	print_name(t_lst_struct *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->file)
		{
			ft_putstr(lst->file->file_name);
			ft_putchar('\n');
		}
		lst = lst->next;
	}
	ft_del_list(&lst);
}
