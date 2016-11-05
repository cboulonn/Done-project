/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:06:24 by cboulonn          #+#    #+#             */
/*   Updated: 2016/05/09 17:09:34 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_iterative_power(int nb, int power)
{
	int	result;
	int	a;

	result = 1;
	a = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (a <= power)
	{
		result = nb * result;
		a++;
	}
	return (result);
}
