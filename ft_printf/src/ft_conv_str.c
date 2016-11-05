/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:22:14 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 17:57:45 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_right_len(t_toprint *save, t_instr *info, char *str)
{
	int		i;

	i = -1;
	if (info->point)
	{
		if (info->cv_spe == 's' || info->cv_spe == 'S' || !info->info_nb)
			while (++i < info->prec && str[i] != '\0')
				ft_put_char(save, str[i]);
		else
			while (++i < info->len && str[i] != '\0')
				ft_put_char(save, str[i]);
	}
	else
		while (++i < info->len && str[i] != '\0')
			ft_put_char(save, str[i]);
}

void	ft_put_right_place_str(t_instr *info, t_toprint *save, char *str)
{
	info->len = ft_strlen(str);
	if (info->prec > info->len)
		info->prec = info->len;
	if (info->width != 0 && !(info->flags & FLAG_M))
	{
		if (info->point)
			ft_put_width(info, save, info->prec);
		else
			ft_put_width(info, save, info->len);
		ft_put_right_len(save, info, str);
	}
	else if (info->width != 0 && (info->flags & FLAG_M))
	{
		ft_put_right_len(save, info, str);
		if (info->point)
			ft_put_width(info, save, info->prec);
		else
			ft_put_width(info, save, info->len);
	}
	else
		ft_put_right_len(save, info, str);
}

int		ft_conv_str(t_instr *info, t_toprint *save)
{
	char	c;
	int		nb;

	if (info->cv_spe == 's')
	{
		ft_conv_str_2(info, save);
	}
	else if (info->cv_spe == 'S')
	{
		if (ft_treatwstr(save, info) == -1)
			return (-1);
	}
	else if (info->mod_exist == 1)
	{
		c = info->cv_spe;
		nb = 1;
		if (info->width)
			nb = info->width;
		if ((save->i_ret + nb) > save->mallen)
			save->ret = ft_realloc(save, nb);
		ft_put_right_place(info, save, c);
	}
	return (0);
}
