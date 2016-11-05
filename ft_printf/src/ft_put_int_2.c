/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:17:21 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/17 14:40:08 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_diese2(t_instr *info, t_toprint *save, char *str)
{
	if (info->cv_spe == 'b' && str[0] != '-')
	{
		save->ret[save->i_ret] = '0';
		save->i_ret++;
		save->ret[save->i_ret] = 'b';
		save->i_ret++;
	}
	else if ((info->flags & FLAG_P) && ft_atoi(str) >= 0 && info->bt2 != 1)
	{
		save->ret[save->i_ret] = '+';
		save->i_ret++;
	}
}

int		ft_put_moins(char **str, t_instr *info, t_toprint *save)
{
	char	*ret;
	char	*sub;

	if (ft_atoi(*str) < 0 && (info->flags & FLAG_0) &&
	!(ret = ft_strchr("oOuUXx", info->cv_spe)))
	{
		save->ret[save->i_ret] = '-';
		save->i_ret++;
		sub = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		free(*str);
		*str = sub;
		info->bt2 = 1;
	}
	return (1);
}

void	ft_prec(char **str, t_instr *info, t_toprint *save)
{
	if (*str[0] == '-' && !info->bt3)
		ft_put_width(info, save, info->prec + 1);
	else
		ft_put_width(info, save, info->prec);
	if (info->prec != 0)
		ft_put_int(info, save, str);
}

void	ft_flag_0_d(char **str, t_instr *info, t_toprint *save)
{
	ft_put_diese_n_plus(info, save, *str);
	ft_put_moins(str, info, save);
	ft_put_width(info, save, info->len);
	ft_put_right_len(save, info, *str);
}

void	ft_dips_prec_flag_else(char **str, t_instr *info, t_toprint *save)
{
	if (info->point)
		ft_prec(str, info, save);
	else if ((info->flags & FLAG_0) && (info->flags & FLAG_D))
		ft_flag_0_d(str, info, save);
	else
	{
		if ((info->flags & FLAG_0) && (info->flags & FLAG_P))
		{
			ft_put_moins(str, info, save);
			if (info->flags & FLAG_D || (info->flags & FLAG_P))
				ft_put_diese_n_plus(info, save, *str);
			ft_put_prec(info, save, str);
			ft_put_width(info, save, info->len);
			ft_put_right_len(save, info, *str);
		}
		else
		{
			ft_put_moins(str, info, save);
			ft_put_width(info, save, info->len);
			ft_put_int(info, save, str);
		}
	}
}
