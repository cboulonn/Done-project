/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:38:16 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/25 16:25:09 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(s);
	if (s != NULL)
	{
		while (i < length)
		{
			f(&s[i]);
			i++;
		}
	}
}
