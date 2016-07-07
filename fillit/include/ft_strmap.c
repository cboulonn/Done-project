/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:20:30 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/02 18:19:53 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		lenght;
	char	*str;

	str = NULL;
	i = -1;
	lenght = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(*s) * lenght + 1);
	if (str)
	{
		while (s[++i])
			str[i] = f(s[i]);
		str[i] = '\0';
	}
	return ((char *)str);
}
