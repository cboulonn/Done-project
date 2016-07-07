/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:32:09 by lbougero          #+#    #+#             */
/*   Updated: 2016/02/15 16:32:08 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t	i;

	i = -1;
	if (dst && src && n > 0)
	{
		while (*((char *)(src + ++i)) != c && i < n)
			*((char *)dst + i) = *((char *)(src + i));
		return ((void *)&(src[i + 1]));
	}
	return (NULL);
}

int		ft_check_line_len(t_struct *s)
{
	int	i;

	i = 0;
	while (s->buf[i++] != '\n')
		;
	while (s->buf[i] != '\0')
	{
		if (s->buf[i] != s->obs && s->buf[i] != s->empty && s->buf[i] != '\n' &&
				s->buf[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_cherror(t_struct *s)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = s->buf;
	i = 0;
	if (s->buf[i] == '\0')
		return (1);
	while (s->buf[i++] != '\n')
		;
	if (ft_check_line_len(s) == 1)
		return (1);
	while (*(tmp++) != '\n')
		;
	while (*tmp != '\0')
	{
		j = ft_linelen(tmp);
		while (*(tmp++) != '\n')
			;
		if (j != s->nb_col)
			return (1);
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int		is_negative;
	int		value;

	is_negative = 0;
	value = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!is_negative)
		value = -value;
	return (value);
}

void	ft_free(t_struct *s, t_square *cor)
{
	int		i;

	i = 0;
	free(s->line);
	free(s->buf);
	while (s->map[i] != NULL)
	{
		free(s->map[i]);
		i++;
	}
	free(s->map);
	if (cor)
		free(cor);
	free(s);
}
