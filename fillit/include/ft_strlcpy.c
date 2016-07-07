/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:26:33 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:50:54 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	char		*cd;
	char		*cs;
	size_t		len;

	cd = dest;
	cs = src;
	len = size;
	if (len != 0)
	{
		while (--len != 0)
		{
			if ((*cd++ = *cs++) == '\0')
				break ;
		}
	}
	if (len == 0)
	{
		if (size != 0)
			*cd = '\0';
		while (*cs++)
			;
	}
	return (cs - src - 1);
}
