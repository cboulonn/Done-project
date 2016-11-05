/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 13:48:05 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 17:53:46 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_right_place_wchar(t_instr *info, t_toprint *save, char *w_char)
{
	int		i;
	int		bt;

	i = -1;
	bt = 0;
	info->len = ft_strlen(w_char);
	if (info->width != 0 && !(info->flags & FLAG_M))
	{
		ft_put_width(info, save, info->len);
		while (++i < info->len)
			ft_put_char(save, w_char[i]);
	}
	else if (info->width != 0 && (info->flags & FLAG_M))
	{
		while (++i < info->len)
			ft_put_char(save, w_char[i]);
		ft_put_width(info, save, info->len);
	}
	else
	{
		while (++i < info->len)
			ft_put_char(save, w_char[i]);
	}
	free(w_char);
}

int		ft_fill_mask(int w_int, int len, int m_0, int m_1)
{
	int		i;
	int		compt;
	int		i_w;
	int		nb;

	i = 1;
	compt = 0;
	i_w = 1;
	nb = 0;
	while (compt != len)
	{
		if (!(m_0 & i) && !(m_1 & i))
		{
			if (w_int & i_w)
				nb |= i;
			i_w <<= 1;
		}
		else if (m_0 & i)
			nb |= i;
		i <<= 1;
		compt++;
	}
	return (nb);
}

int		ft_wchar_len(int w_int)
{
	int		i;

	i = 0;
	while (w_int > 0)
	{
		w_int >>= 1;
		i++;
	}
	return (i);
}

char	*ft_get_wchar(int w_int)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	str = NULL;
	i = -1;
	len = ft_wchar_len(w_int);
	if (len == 0)
		return (NULL);
	if (len < 8 && (len = 1))
		;
	else if (len < 12 && (len = 2))
		w_int = ft_fill_mask(w_int, 16, BM1_0, BM1_1);
	else if (len < 17 && (len = 3))
		w_int = ft_fill_mask(w_int, 24, BM2_0, BM2_1);
	else if (len < 22 && (len = 4))
		w_int = ft_fill_mask(w_int, 32, BM3_0, BM3_1);
	else
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	while (len--)
		str[++i] = ((w_int >> (8 * len)) & ~((unsigned)-1 << 8));
	str[++i] = '\0';
	return (str);
}

int		ft_treatwchar(t_toprint *save, t_instr *info)
{
	int		w_int;
	char	*w_char;
	char	c;
	int		len;

	w_int = va_arg(save->ap, int);
	if (w_int == 0)
	{
		c = '\0';
		ft_put_right_place(info, save, c);
		return (0);
	}
	if ((w_char = ft_get_wchar(w_int)) != NULL)
	{
		len = ft_strlen(w_char);
		if (len < info->width)
			len = info->width;
		if ((save->i_ret + len) > save->mallen)
			save->ret = ft_realloc(save, len);
		ft_put_right_place_wchar(info, save, w_char);
	}
	else
		return (-1);
	return (0);
}
