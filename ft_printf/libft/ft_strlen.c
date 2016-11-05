/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 22:12:48 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/10 13:51:07 by gbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			i++;
		}
	return (i);
}
