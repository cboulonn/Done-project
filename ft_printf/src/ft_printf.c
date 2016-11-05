/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:05:00 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/20 14:30:04 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_cv_spe(char *str, t_instr *info, t_toprint *save)
{
	char	*ret;
	int		r;
	char	*signe;
	char	*unsigne;

	signe = "dDi";
	unsigne = "oOuUXxpb";
	if (!info->cv_spe)
		return (0);
	if (!(ret = ft_strchr(str, info->cv_spe)))
	{
		info->mod_exist = 1;
		if ((r = ft_conv_char(info, save)) == -1)
			return (-1);
	}
	else
	{
		ret = NULL;
		if ((ret = ft_strchr(signe, info->cv_spe)))
			ft_int_signed(info, save);
		if ((ret = ft_strchr(unsigne, info->cv_spe)))
			ft_int_unsigned(info, save);
	}
	return (1);
}

int		ft_get_instr(t_toprint *save, char *fmt)
{
	t_instr		*info;
	char		*str;
	int			ret;
	int			r;

	str = "sSpdDioOuUxXcCb";
	info = NULL;
	info = ft_init_struct_instr(info);
	ft_parse_instr(info, save, fmt);
	r = 0;
	if (info->cv_spe == 'c' || info->cv_spe == 'C')
		if ((r = ft_conv_char(info, save)) == -1)
			return (r = ft_error_ftprintf(&info));
	if (info->cv_spe == 's' || info->cv_spe == 'S')
	{
		if ((r = ft_conv_str(info, save)) == -1)
			return (r = ft_error_ftprintf(&info));
	}
	else
	{
		if ((ret = ft_check_cv_spe(str, info, save)) == -1)
			return (r = ft_error_ftprintf(&info));
	}
	free(info);
	return (1);
}

char	*ft_cpy_no_malloc(char *dst, const char *fmt, t_toprint *save)
{
	char	*new;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if ((save->i_ret) < save->mallen)
	{
		dst[save->i_ret] = fmt[save->i_fmt];
		return (dst);
	}
	else
	{
		new = (char *)malloc(sizeof(char) * (save->mallen + 1000));
		ft_strncpy(new, dst, save->mallen);
		free(dst);
		dst = NULL;
		ft_bzero(&new[save->mallen], 1000);
		new[save->i_ret] = fmt[save->i_fmt];
		save->mallen += 1000;
		return (new);
	}
}

int		ft_printf2(t_toprint *save, const char *fmt)
{
	int		ret;

	//ft_putendl("bla");
	if (fmt[save->i_fmt] == '%')
	{
		if ((ret = ft_get_instr(save, (char *)fmt + 1)) != -1)
			save->i_fmt++;
		else
			return (-1);
	}
	else
	{
		save->ret = ft_cpy_no_malloc(save->ret, fmt, save);
		save->i_ret++;
		save->i_fmt++;
	}
	return (0);
}

int		ft_printf(const char *fmt, ...)
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
	ret = 0;
	while (fmt[save->i_fmt] != '\0')
		ret = ft_printf2(save, fmt);
	//write(2, "AAAAAAAAAAAAAAAAA\n", 18);
	save->ret[save->i_ret] = '\0';
	write(1, save->ret, save->i_ret);
	free(save->ret);
	va_end(save->ap);
	ret = save->i_ret;
	free(save);
	return (ret);
}
