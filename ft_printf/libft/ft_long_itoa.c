/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:50:33 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/10 14:26:35 by gbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_nblen(long n)
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

char			*ft_long_itoa(long n)
{
	int		i;
	char	*value;

	i = ft_nblen(n);
	value = NULL;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	if ((value = ft_strnew(i)))
	{
		if (n < 0)
		{
			n = -n;
			value[0] = '-';
		}
		while (--i >= 0 && value[i] != '-')
		{
			value[i] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (value);
}
