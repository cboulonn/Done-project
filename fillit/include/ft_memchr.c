/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:00:05 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:46:44 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n)
	{
		while (i < n && ((unsigned char *)str)[i] != (unsigned char)c)
			i++;
		if (i == n)
			return (NULL);
	}
	return ((&((unsigned char *)str)[i]));
}
