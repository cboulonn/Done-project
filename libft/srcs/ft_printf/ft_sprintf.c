/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:53:32 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 18:01:33 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_sprintf(const char *fmt, ...)
{
	t_toprint	*save;
	int			ret;
	char		*toret;

	if (fmt == NULL)
		return (NULL);
	save = NULL;
	save = ft_init_struct_toprint(save);
	va_start(save->ap, fmt);
	save->ret = (char *)malloc(sizeof(char) * 1000);
	ft_bzero(save->ret, 1000);
	while (fmt[save->i_fmt] != '\0')
		ret = ft_printf2(save, fmt);
	if (ret == -1)
		return ("(NULL)");
	save->ret[save->i_ret] = '\0';
	toret = save->ret;
	free(save);
	return (toret);
}
