/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:25:53 by cboulonn          #+#    #+#             */
/*   Updated: 2016/04/12 11:01:22 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*save_map;
	t_list	*map;

	save_map = NULL;
	if ((save_map = f(lst)) == NULL)
		return (NULL);
	map = save_map;
	map->next = NULL;
	while (lst->next)
	{
		lst = lst->next;
		map->next = f(lst);
		if (map->next == NULL)
			return (NULL);
		map = map->next;
	}
	return (save_map);
}
