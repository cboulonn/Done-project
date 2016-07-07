/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:43:34 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/15 18:01:15 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char		*ft_strjoin_n_free(char *s1, char *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (res);
}

void	ft_free_buf(t_struct *s)
{
	write(2, "map error\n", 10);
	free(s->buf);
	exit(42);
}
