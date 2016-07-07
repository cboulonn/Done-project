/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:00:05 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/02 17:19:49 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n > 0)
	{
		while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		if (i != n)
			return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	}
	return (0);
}
