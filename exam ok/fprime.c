/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:20:36 by exam              #+#    #+#             */
/*   Updated: 2016/09/27 12:04:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_decompose_toi(char *nbr)
{
	int		nb;
	int		dc;
	
	nb = atoi(nbr);
	if (nb == 1)
	{
		printf("1\n");
		return (0);
	}
	while (nb != 1)
	{
		dc = 2;
		while (nb % dc != 0)
			dc++;	
		printf("%i", dc);
		nb = nb / dc;
		if (nb != 1)
			printf("*");
	}
	printf("\n");
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	ft_decompose_toi(argv[1]);
	return(0);	
}
