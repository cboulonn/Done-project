/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 15:23:38 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/17 14:46:27 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_error_ftprintf(t_instr **info)
{
	free(*info);
	return (-1);
}

t_instr		*ft_parse_instr(t_instr *info, t_toprint *save, char *fmt)
{
	int		i;

	i = save->i_fmt;
	ft_get_flags(info, fmt, &i);
	ft_get_width(info, fmt, &i, save);
	ft_get_prec(info, fmt, &i, save);
	ft_get_length_mod(info, fmt, &i);
	ft_get_conv_spe(info, fmt, &i);
	save->i_fmt = i;
	ft_reparse_instr(info);
	return (info);
}

t_instr		*ft_reparse_instr(t_instr *info)
{
	if ((info->flags & FLAG_M) && (info->flags & FLAG_0))
		info->flags &= ~FLAG_0;
	if (info->width < 0)
	{
		info->flags |= FLAG_M;
		info->width = FT_ABS(info->width);
	}
	if (info->point)
	{
		if (info->cv_spe == 'c' || info->cv_spe == 'C')
		{
			info->point = 0;
			info->prec = 0;
		}
	}
	ft_flags_cv_spe(info);
	ft_flags(info);
	return (info);
}

void		ft_flags_cv_spe(t_instr *info)
{
	if ((info->l_mod & LM_L) && (info->cv_spe == 'c'))
		info->cv_spe = 'C';
	if ((info->l_mod & LM_L) && (info->cv_spe == 's'))
		info->cv_spe = 'S';
	if ((info->l_mod & LM_L) && (info->cv_spe == 'd'))
		info->cv_spe = 'D';
	if ((info->l_mod & LM_L) && (info->cv_spe == 'o'))
		info->cv_spe = 'O';
	if ((info->l_mod & LM_L) && (info->cv_spe == 'u'))
		info->cv_spe = 'U';
	if (info->cv_spe == 'p')
	{
		if (!(info->flags & FLAG_D))
			info->flags |= FLAG_D;
		info->l_mod |= LM_L;
	}
	if (info->cv_spe == 'U')
		if (info->l_mod)
		{
			info->l_mod = 0;
			info->l_mod |= LM_L;
			info->cv_spe = 'u';
		}
}

void		ft_flags(t_instr *info)
{
	if (info->cv_spe == 'i' || info->cv_spe == 'd' || info->cv_spe == 'u')
		info->flags &= ~FLAG_D;
	if (info->flags & FLAG_P)
	{
		if (info->cv_spe != 'd' && info->cv_spe != 'D' && info->cv_spe != 'i')
			info->flags &= ~FLAG_P;
	}
	if ((info->flags & FLAG_E))
	{
		if ((info->cv_spe != 'd' && info->cv_spe != 'D' && info->cv_spe != 'i')
					|| info->flags & FLAG_P)
			info->flags &= ~FLAG_E;
	}
	if ((info->flags & FLAG_0) && (info->prec > 0))
	{
		if (info->cv_spe == 'd' || info->cv_spe == 'i' || info->cv_spe == 'o'
			|| info->cv_spe == 'u' || info->cv_spe == 'x' ||
			info->cv_spe == 'X' || info->cv_spe == 'p')
			info->flags &= ~FLAG_0;
	}
	if (info->prec < 0)
	{
		info->point = 0;
		info->prec = 0;
	}
}
