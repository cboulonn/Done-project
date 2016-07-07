/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:00:21 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 17:52:22 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (ft_strncmp((char *)s1, (char *)s2, n) == 0)
		return (1);
	return (0);
}
