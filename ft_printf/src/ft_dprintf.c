/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:55:59 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 16:32:06 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_dprintf(int fd, const char *fmt, ...)
{
	t_toprint	*save;
	int			ret;

	if (fmt == NULL)
		return (-1);
	save = NULL;
	save = ft_init_struct_toprint(save);
	va_start(save->ap, fmt);
	save->ret = (char *)malloc(sizeof(char) * 1000);
	ft_bzero(save->ret, 1000);
	while (fmt[save->i_fmt] != '\0')
		ret = ft_printf2(save, fmt);
	save->ret[save->i_ret] = '\0';
	if (ret == -1)
	{
		write(2, "ERROR", 5);
		return (-1);
	}
	write(fd, save->ret, save->i_ret);
	free(save->ret);
	va_end(save->ap);
	ret = save->i_ret;
	free(save);
	return (ret);
}
