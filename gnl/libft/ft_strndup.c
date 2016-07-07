/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:48:17 by cboulonn          #+#    #+#             */
/*   Updated: 2016/04/23 14:32:13 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, char n)
{
	char	*copie;
	int		i;

	i = 0;
	copie = NULL;
	if ((copie = (char *)malloc(sizeof(*s1) * (ft_linelen(s1, '\n') + 1))))
	{
		while (s1[i] != n && s1[i] != '\0')
		{
			copie[i] = s1[i];
			i++;
		}
		copie[i] = '\0';
	}
	return (copie);
}
