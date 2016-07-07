/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:00:05 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:47:55 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (len > 0)
	{
		if (src > dest)
			while (i < len)
			{
				((char *)dest)[i] = ((char *)src)[i];
				i++;
			}
		if (i != len)
			while (len-- != 0)
				((char *)dest)[len] = ((char *)src)[len];
	}
	return (dest);
}
