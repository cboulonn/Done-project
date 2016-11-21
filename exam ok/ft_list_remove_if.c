#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;
	t_list	*t;
	while(*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		list = *begin_list;
		*begin_list = (*begin_list)->next;
		free(list);
	}
	t = *begin_list;
	while(t && t->next)
	{
		if(cmp(t->next->data, data_ref) == 0)
		{
			list = t->next;
			t->next = list->next;
			free(list);
		}
		if (t->next)
			t = t->next;
	}
}
