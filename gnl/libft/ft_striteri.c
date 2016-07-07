/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:38:36 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/25 16:49:14 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(s);
	if (s != NULL)
	{
		while (i < length)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
