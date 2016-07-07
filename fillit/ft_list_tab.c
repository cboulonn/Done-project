/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:32:43 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/24 17:32:34 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "fillit.h"

char		*ft_strjoin_n_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (res);
}

int			ft_tablen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_chain		*ft_chainlisttab2(t_chain *tmp, char **save, int *i, int k)
{
	while (++k < 4 && save[*i])
		tmp->data[k] = ft_strdup(save[(*i)++]);
	if (save[*i])
	{
		tmp->next = (t_chain *)malloc(sizeof(t_chain));
		tmp = tmp->next;
	}
	else
		tmp->data[k] = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_chain		*chainlisttab(t_struct *s, t_chain *tmp)
{
	int		i;
	int		k;
	t_chain	*listtab;
	char	**save;

	i = 0;
	k = -1;
	listtab = NULL;
	listtab = (t_chain *)malloc(sizeof(t_chain));
	save = ft_strsplit(s->buf, '\n');
	tmp = (t_chain *)malloc(sizeof(t_chain));
	tmp = listtab;
	while (save[i])
	{
		k = -1;
		tmp->data = (char **)malloc(sizeof(char *) * (ft_tablen(save) + 1));
		tmp = ft_chainlisttab2(tmp, save, &i, k);
	}
	tmp = listtab;
	i = 0;
	ft_free_all_tab(save);
	return (tmp);
}
