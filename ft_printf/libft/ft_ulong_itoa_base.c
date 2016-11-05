/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:05:44 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/03 10:14:44 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_ulong_itoa_base(unsigned long nbr, char *base_to)
{
	char				*ans;
	int					power;
	int					baselen;
	unsigned long		i;

	baselen = ft_strlen(base_to);
	power = 1;
	i = nbr;
	while ((i /= baselen))
		power++;
	ans = (char*)malloc(power + 1);
	ans[power] = '\0';
	while (power--)
	{
		ans[power] = base_to[nbr % baselen];
		nbr /= baselen;
	}
	return (ans);
}
