/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:47:26 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/03 14:54:21 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base(unsigned int nbr, char *base_to)
{
	char	*ans;
	int		power;
	int		baselen;
	int		i;

	baselen = ft_strlen(base_to);
	power = 0;
	i = nbr;
	while (i >= baselen)
	{
		i = i / baselen;
		power++;
	}
	ans = (char*)malloc(power + 1);
	while (power >= 0)
	{
		ans[power] = base_to[nbr % baselen];
		nbr = (nbr - nbr % baselen) / baselen;
		power--;
	}
	return (ans);
}
