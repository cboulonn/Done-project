/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 14:32:48 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:47:08 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*value;

	i = ft_nblen(n);
	value = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if ((value = ft_strnew(i)))
	{
		if (n < 0)
		{
			n = -n;
			value[0] = '-';
		}
		while (i >= 0 && value[--i] != '-')
		{
			value[i] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (value);
}
