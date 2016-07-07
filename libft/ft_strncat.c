/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 13:57:51 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/25 16:27:17 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		cd;
	size_t	cs;

	cd = 0;
	cs = 0;
	while (s1[cd] != '\0')
		cd++;
	while (s2[cs] != '\0' && cs < n)
	{
		s1[cd] = s2[cs];
		cd++;
		cs++;
	}
	s1[cd] = '\0';
	return (s1);
}
