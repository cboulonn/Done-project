/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:00:58 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/25 16:41:10 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *tron;

	tron = NULL;
	if (s)
	{
		tron = ft_strnew(len);
		if (tron != NULL)
		{
			tron = ft_strncpy(tron, s + start, len);
		}
	}
	return (tron);
}
