/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:26:30 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/25 14:26:48 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = NULL;
	if (size != 0)
	{
		if ((p = (void *)malloc(size)) != NULL)
			ft_bzero(p, size);
	}
	return (p);
}
