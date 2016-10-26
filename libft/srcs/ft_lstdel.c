/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:42:53 by cboulonn          #+#    #+#             */
/*   Updated: 2016/04/12 13:44:03 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*deletelist;
	t_list	*list;

	if (*alst != NULL && del != NULL)
	{
		deletelist = *alst;
		while (deletelist)
		{
			(*del)(deletelist->content, deletelist->content_size);
			list = deletelist->next;
			free(deletelist);
			deletelist = list;
		}
	}
	*alst = NULL;
}
