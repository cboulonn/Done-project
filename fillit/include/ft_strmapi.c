/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 11:11:13 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/02 18:20:33 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		lenght;
	char	*s2;

	s2 = NULL;
	i = -1;
	lenght = ft_strlen((char *)s);
	s2 = (char *)malloc(sizeof(*s) * lenght + 1);
	if (s2)
	{
		while (s[++i])
			s2[i] = f(i, s[i]);
		s2[i] = '\0';
	}
	return (s2);
}
