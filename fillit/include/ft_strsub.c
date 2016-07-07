/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:13:54 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/02 18:31:53 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *cpy;

	cpy = NULL;
	if (s)
	{
		if ((cpy = ft_strnew(len)))
			cpy = ft_strncpy(cpy, (char *)s + start, len);
	}
	return (cpy);
}
