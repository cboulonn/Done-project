/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:33:39 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/03 17:47:10 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_linelen(char *str)
{
	int i;

	i = 0;
	while (*str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	unsigned		int	t;
	int					s;

	s = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	t = nb;
	while ((t /= 10) > 0)
	{
		s *= 10;
	}
	t = nb;
	while (s)
	{
		ft_putchar((t / s) + 48);
		t = t % s;
		s = s / 10;
	}
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
