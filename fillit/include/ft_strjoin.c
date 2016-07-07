/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:27:41 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/29 19:02:13 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	cpy = NULL;
	cpy = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (cpy != NULL)
	{
		ft_strcpy(cpy, (char *)s1);
		ft_strcpy(cpy + ft_strlen((char *)s1), (char *)s2);
	}
	return (cpy);
}
