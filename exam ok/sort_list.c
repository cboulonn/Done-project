/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 10:10:34 by exam              #+#    #+#             */
/*   Updated: 2016/10/04 11:06:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *beg;
	int		c;

	beg = lst;
	while(lst->next)
	{
		if(cmp(lst->data, lst->next->data) == 0)
		{
			c = lst->data;
			lst->data = lst->next->data;
			lst->next->data = c;
			lst = beg;
		}
		else
			lst = lst->next;
	}
	lst = beg;
	return(lst);
}
