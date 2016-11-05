/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:15:27 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 17:51:50 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_conv_str_2(t_instr *info, t_toprint *save)
{
	int		size;
	char	*str;

	str = va_arg(save->ap, char*);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	if (size < info->width)
		size = info->width;
	if ((save->i_ret + size) > save->mallen)
		save->ret = ft_realloc(save, size);
	ft_put_right_place_str(info, save, str);
}
