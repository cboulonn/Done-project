/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:37:18 by cboulonn          #+#    #+#             */
/*   Updated: 2016/04/18 16:51:30 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copie;
	int		i;

	i = 0;
	if ((copie = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))))
	{
		while (s1[i] != '\0')
		{
			copie[i] = s1[i];
			i++;
		}
		copie[i] = '\0';
	}
	return (copie);
}
