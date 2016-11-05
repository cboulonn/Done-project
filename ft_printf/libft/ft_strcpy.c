/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:36:49 by cboulonn          #+#    #+#             */
/*   Updated: 2016/09/02 13:58:05 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int compt;

	compt = 0;
	while (src[compt] != '\0')
	{
		dst[compt] = src[compt];
		compt++;
	}
	dst[compt] = src[compt];
	return (dst);
}
