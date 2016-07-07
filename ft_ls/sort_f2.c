/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_f2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:37:04 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 10:07:50 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_swap2(t_list **tmp, t_list **tmp2)
{
	void	*tmp_data;

	tmp_data = (*tmp)->content;
	(*tmp)->content = (*tmp2)->content;
	(*tmp2)->content = tmp_data;
}

t_list		*ft_sort(t_optnarg *disp_arg, t_info *info, t_info *info2,
	t_list *tmp)
{
	t_list	*tmp2;
	int		ret;

	tmp2 = tmp->next;
	ret = ft_cmp_alpha_n_time2(info, info2, tmp);
	if (ret < 0)
	{
		ft_swap2(&tmp, &tmp2);
		tmp = disp_arg->arg;
	}
	else
		tmp = tmp->next;
	return (tmp);
}

void		sort_reverse_list(t_list **list)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *list;
	c = NULL;
	while (a != NULL)
	{
		b = a->next;
		a->next = c;
		c = a;
		a = b;
	}
	*list = c;
}
