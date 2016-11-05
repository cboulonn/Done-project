/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:14:40 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 17:59:12 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_realloc(t_toprint *save, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (save->i_ret + len));
	str = ft_strcpy(str, save->ret);
	ft_bzero(&str[save->i_ret], len);
	save->mallen = save->i_ret + len;
	free(save->ret);
	save->ret = NULL;
	return (str);
}

void	ft_put_right_place(t_instr *info, t_toprint *save, char c)
{
	info->len = 1;
	if (info->width != 0 && !(info->flags & FLAG_M))
	{
		ft_put_width(info, save, info->len);
		ft_put_char(save, c);
	}
	else if (info->width != 0 && (info->flags & FLAG_M))
	{
		ft_put_char(save, c);
		ft_put_width(info, save, info->len);
	}
	else
		ft_put_char(save, c);
}

void	ft_put_width(t_instr *info, t_toprint *save, int len)
{
	int		b;

	b = -1;
	while (++b < info->width - len)
	{
		if (info->flags & FLAG_0)
			save->ret[save->i_ret] = '0';
		else
			save->ret[save->i_ret] = ' ';
		save->i_ret++;
	}
}

void	ft_put_char(t_toprint *save, char c)
{
	if (c)
	{
		save->ret[save->i_ret] = c;
		save->i_ret++;
	}
	else
	{
		save->ret[save->i_ret] = '\0';
		save->i_ret++;
	}
}

int		ft_conv_char(t_instr *info, t_toprint *save)
{
	char	c;
	int		nb;

	c = 0;
	nb = 1;
	if (info->width)
		nb = info->width;
	if ((save->i_ret + nb) > save->mallen)
		save->ret = ft_realloc(save, nb);
	if (info->cv_spe == 'c')
	{
		c = va_arg(save->ap, int);
		ft_put_right_place(info, save, c);
	}
	else if (info->cv_spe == 'C')
	{
		if (ft_treatwchar(save, info) == -1)
			return (-1);
	}
	else if (info->mod_exist == 1)
	{
		c = info->cv_spe;
		ft_put_right_place(info, save, c);
	}
	return (0);
}
