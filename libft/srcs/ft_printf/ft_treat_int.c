/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:07:28 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/17 14:33:10 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_get_base(unsigned long nb, t_instr *info)
{
	char	*str;

	str = NULL;
	if (info->cv_spe == 'u' || info->cv_spe == 'U')
		str = ft_ulong_itoa_base(nb, "0123456789");
	if (info->cv_spe == 'o' || info->cv_spe == 'O')
		str = ft_ulong_itoa_base(nb, "01234567");
	if (info->cv_spe == 'x' || info->cv_spe == 'p')
		str = ft_ulong_itoa_base(nb, "0123456789abcdef");
	if (info->cv_spe == 'X')
		str = ft_ulong_itoa_base(nb, "0123456789ABCDEF");
	if (info->cv_spe == 'b')
		str = ft_ulong_itoa_base(nb, "01");
	return (str);
}

void	ft_int_signed(t_instr *info, t_toprint *save)
{
	long	nb;
	char	*str;

	nb = 0;
	if ((info->l_mod & LM_H))
		nb = (short)va_arg(save->ap, int);
	else if ((info->l_mod & LM_L) || info->cv_spe == 'D')
		nb = (long)va_arg(save->ap, long);
	else if ((info->l_mod & LM_J))
		nb = va_arg(save->ap, intmax_t);
	else if ((info->l_mod & LM_Z))
		nb = va_arg(save->ap, ssize_t);
	else if ((info->l_mod & LM_HH))
		nb = (char)va_arg(save->ap, int);
	else if ((info->l_mod & LM_LL))
		nb = (long long)va_arg(save->ap, long);
	else
		nb = va_arg(save->ap, int);
	info->info_nb = nb;
	str = ft_long_itoa(nb);
	ft_dispatch_flag(info, save, &str);
	free(str);
}

void	ft_int_unsigned(t_instr *info, t_toprint *save)
{
	unsigned long	nb;
	char			*str;

	nb = 0;
	if ((info->l_mod & LM_H))
		nb = (unsigned short)va_arg(save->ap, int);
	else if ((info->l_mod & LM_L) || info->cv_spe == 'O' || info->cv_spe == 'U')
		nb = (unsigned long)va_arg(save->ap, long);
	else if ((info->l_mod & LM_J))
		nb = va_arg(save->ap, unsigned long);
	else if ((info->l_mod & LM_Z))
		nb = va_arg(save->ap, size_t);
	else if ((info->l_mod & LM_HH))
		nb = (unsigned char)va_arg(save->ap, int);
	else if ((info->l_mod & LM_LL))
		nb = (unsigned long long)va_arg(save->ap, long);
	else
		nb = va_arg(save->ap, unsigned int);
	info->info_nb = nb;
	str = ft_get_base(nb, info);
	ft_dispatch_flag(info, save, &str);
	free(str);
}
