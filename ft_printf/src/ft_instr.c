/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:24:13 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/12 16:41:59 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_flags(t_instr *info, char *fmt, int *i)
{
	char	*ret;

	while (fmt[*i] != '\0' && (ret = ft_strchr("#0-+ ", fmt[*i])))
	{
		info->flags |= ft_iterative_power(2, (ret - "#0-+ "));
		(*i)++;
	}
}

void	ft_get_width(t_instr *info, char *fmt, int *i, t_toprint *save)
{
	char	*nb;
	char	*ret;

	nb = "0123456789";
	while ((fmt[*i] != '\0' && (ret = ft_strchr(nb, fmt[*i]))) ||
	fmt[*i] == '*')
	{
		if (fmt[*i] != '\0' && (ret = ft_strchr(nb, fmt[*i])))
		{
			info->width = ft_atoi(fmt + *i);
			while (fmt[*i] >= '0' && fmt[*i] <= '9')
				(*i)++;
		}
		else if (fmt[*i] == '*')
		{
			info->width = va_arg(save->ap, int);
			(*i)++;
		}
		ft_get_width(info, fmt, i, save);
	}
}

void	ft_get_prec(t_instr *info, char *fmt, int *i, t_toprint *save)
{
	while ((fmt[*i] != '\0' && fmt[*i] == '.') || fmt[*i] == '*')
	{
		if (fmt[*i] != '\0' && fmt[*i] == '.')
		{
			info->point = 1;
			(*i)++;
			if (fmt[*i] == '*')
			{
				info->prec = va_arg(save->ap, int);
				(*i)++;
			}
			else
			{
				info->prec = ft_atoi(fmt + *i);
				while (fmt[*i] >= '0' && fmt[*i] <= '9')
					(*i)++;
			}
		}
		ft_get_prec(info, fmt, i, save);
	}
}

void	ft_get_length_mod(t_instr *info, char *fmt, int *i)
{
	char	*ret;

	while (fmt[*i] != '\0' && (ret = ft_strchr("hljz", fmt[*i])))
	{
		if (fmt[*i] == 'h' && fmt[*i + 1] == 'h')
		{
			info->l_mod = LM_HH;
			(*i)++;
		}
		else if (fmt[*i] == 'l' && fmt[*i + 1] == 'l')
		{
			info->l_mod = LM_LL;
			(*i)++;
		}
		else
			info->l_mod = ft_iterative_power(2, (ret - "hljz"));
		(*i)++;
	}
}

void	ft_get_conv_spe(t_instr *info, char *fmt, int *i)
{
	if (fmt[*i] != '\0')
	{
		info->cv_spe = fmt[*i];
		(*i)++;
	}
}
