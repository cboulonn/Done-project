/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:19:16 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/02 13:34:43 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t		i;

	i = ft_strlen(dest);
	if (i >= size)
		return (ft_strlen(src) + size);
	ft_strncat(dest, src, size - i - 1);
	return (ft_strlen(src) + i);
}
