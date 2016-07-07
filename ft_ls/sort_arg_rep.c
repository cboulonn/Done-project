/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_rep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:13:16 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 10:06:44 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_sort_arg_rep(t_optnarg *disp_arg, DIR *dir)
{
	DIR				*dir2;
	t_list			*tmp;
	t_list			*tmpb;
	int				a;
	int				b;

	tmp = disp_arg->arg;
	tmpb = tmp->next;
	a = 0;
	b = 0;
	while (tmp->next)
	{
		dir = opendir(tmp->content);
		dir2 = opendir(tmpb->content);
		a = ft_idontknow(disp_arg, tmp);
		b = ft_idontknow(disp_arg, tmpb);
		tmp = ft_sort2(disp_arg, a, b, tmp);
		tmpb = tmp->next;
	}
}

t_list		*ft_sort2(t_optnarg *disp_arg, int a, int b,
	t_list *tmp)
{
	t_list	*tmp2;
	int		ret;

	tmp2 = tmp->next;
	ret = ft_cmp(a, b);
	if (ret < 0)
	{
		ft_swap2(&tmp, &tmp2);
		tmp = disp_arg->arg;
	}
	else
		tmp = tmp->next;
	return (tmp);
}

int			ft_cmp(int a, int b)
{
	if (a < b)
		return (1);
	if (a > b)
		return (-1);
	if (a == b)
		return (0);
	return (0);
}

int			ft_idontknow(t_optnarg *disp_arg, t_list *tmp)
{
	t_info			*info;
	int				a;

	a = 0;
	info = ft_get_info(tmp->content, NULL, disp_arg->opt);
	if (info == NULL)
	{
		a = 1;
		return (1);
	}
	if (info->right[0] == '-')
	{
		a = 1;
		return (1);
	}
	else
	{
		a = 2;
		return (2);
	}
}
