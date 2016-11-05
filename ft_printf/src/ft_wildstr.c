/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 10:34:32 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/19 17:55:30 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_right_wstrlen(t_toprint *save, char *str, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		ft_put_char(save, str[i]);
}

void	ft_put_right_place_wstr(t_instr *info, t_toprint *save, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (info->width != 0 && !(info->flags & FLAG_M))
	{
		ft_put_width(info, save, len);
		ft_put_right_wstrlen(save, str, len);
	}
	else if (info->width != 0 && (info->flags & FLAG_M))
	{
		ft_put_right_wstrlen(save, str, len);
		ft_put_width(info, save, len);
	}
	else
		ft_put_right_wstrlen(save, str, len);
	free(str);
}

void	ft_get_wstrlen(t_toprint *save, t_instr *info, char *w_char)
{
	int		len;

	len = 0;
	len = ft_strlen(w_char);
	if (len < info->width)
		len = info->width;
	if ((save->i_ret + len) > save->mallen)
		save->ret = ft_realloc(save, len);
}

int		ft_treatwstr2(t_toprint *save, t_instr *info, wchar_t *w_str_fmt,
	char *w_char)
{
	char	*new;
	int		i;

	i = -1;
	new = NULL;
	while (w_str_fmt[++i] != '\0')
	{
		if ((w_char = ft_get_wchar(w_str_fmt[i])) != NULL)
		{
			ft_get_wstrlen(save, info, w_char);
			if (((int)(ft_strlen(w_char) + ft_strlen(new)) <= info->prec) ||
			!(info->point))
				new = ft_strjoin_n_free(new, w_char);
			else
			{
				free(w_char);
				break ;
			}
			free(w_char);
		}
		else
			return (-1);
	}
	ft_put_right_place_wstr(info, save, new);
	return (0);
}

int		ft_treatwstr(t_toprint *save, t_instr *info)
{
	wchar_t	*w_str_fmt;
	char	*w_char;
	int		i;

	i = 0;
	w_char = NULL;
	if ((w_str_fmt = va_arg(save->ap, wchar_t *)) == NULL)
	{
		ft_put_right_place_str(info, save, "(null)");
		return (0);
	}
	i = ft_treatwstr2(save, info, w_str_fmt, w_char);
	return (i);
}
