/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:40:07 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:49:04 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;
	int				size;

	size = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	temp = n;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = n;
	while (size)
	{
		ft_putchar_fd((temp / size) + 48, fd);
		temp = temp % size;
		size = size / 10;
	}
}
