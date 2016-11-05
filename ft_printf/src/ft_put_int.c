/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:12:11 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 17:56:21 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_diese_n_plus(t_instr *info, t_toprint *save, char *str)
{
	if ((info->cv_spe == 'x' && ft_atoi(str) > 0) || info->cv_spe == 'p')
	{
		save->ret[save->i_ret] = '0';
		save->i_ret++;
		save->ret[save->i_ret] = 'x';
		save->i_ret++;
	}
	else if (info->cv_spe == 'X' && ft_atoi(str) > 0)
	{
		save->ret[save->i_ret] = '0';
		save->i_ret++;
		save->ret[save->i_ret] = 'X';
		save->i_ret++;
	}
	else
		ft_put_diese2(info, save, str);
}

void	ft_put_int(t_instr *info, t_toprint *save, char **str)
{
	if (info->flags & FLAG_D || (info->flags & FLAG_P))
		ft_put_diese_n_plus(info, save, *str);
	ft_put_prec(info, save, str);
	if (*str[0] == '-' && info->prec + 1 == info->len)
		info->prec++;
	if ((info->cv_spe == 'o' || info->cv_spe == 'O') && (info->flags & FLAG_D))
	{
		if ((info->point == 1 && str[1] == 0) || str[1] != 0)
		{
			save->ret[save->i_ret] = '0';
			save->i_ret++;
		}
	}
	ft_put_right_len(save, info, *str);
}

int		ft_put_prec(t_instr *info, t_toprint *save, char **str)
{
	char	*sub;
	int		i;

	i = -1;
	if (info->prec >= info->len)
	{
		i = info->len;
		if (*str[0] == '-')
		{
			save->ret[save->i_ret] = '-';
			save->i_ret++;
			sub = ft_strsub(*str, 1, ft_strlen(*str) - 1);
			free(*str);
			*str = sub;
			if (info->bt3 == 0)
				info->prec++;
		}
		while (i < info->prec)
		{
			save->ret[save->i_ret] = '0';
			save->i_ret++;
			++i;
		}
	}
	return (1);
}

void	ft_put_right_place_int(t_instr *info, t_toprint *save, char **str)
{
	int		i;

	i = 0;
	if (info->point && (info->prec != 0) && (info->prec < (int)ft_strlen(*str)))
	{
		info->prec = info->len;
		info->bt3 = 1;
	}
	if ((info->cv_spe == 'o' || info->cv_spe == 'O') && (info->flags & FLAG_D))
		info->len++;
	if (info->width != 0 && !(info->flags & FLAG_M))
	{
		ft_dips_prec_flag_else(str, info, save);
	}
	else if (info->width != 0 && (info->flags & FLAG_M))
	{
		ft_put_moins(str, info, save);
		ft_put_int(info, save, str);
		if (info->point)
			ft_put_width(info, save, info->prec);
		else
			ft_put_width(info, save, info->len);
	}
	else
		ft_put_int(info, save, str);
}

void	ft_dispatch_flag(t_instr *info, t_toprint *save, char **str)
{
	int		nb;

	info->len = ft_strlen(*str);
	nb = info->len;
	if (nb < info->prec)
		nb = info->prec;
	if (nb < info->width)
		nb = info->width;
	if ((save->i_ret + nb) > save->mallen)
		save->ret = ft_realloc(save, nb);
	if ((info->flags & FLAG_E) && ft_atoi(*str) >= 0)
	{
		save->ret[save->i_ret] = ' ';
		save->i_ret++;
		info->len++;
		info->prec++;
	}
	if (info->flags & FLAG_D && info->cv_spe != 'o' && info->cv_spe != 'O'
	&& info->width != 0)
		info->width = info->width - 2;
	if (info->flags & FLAG_P && ft_atoi(*str) >= 0)
		info->width = info->width - 1;
	ft_put_right_place_int(info, save, str);
}
