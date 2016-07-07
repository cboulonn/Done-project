/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:37:10 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:52:04 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char *instr;
	char *intof;
	char *begin;

	if (!*to_find)
		return (str);
	instr = str;
	intof = to_find;
	while (*instr)
	{
		begin = instr;
		while (*instr == *intof && *instr && *intof)
		{
			if (intof[1] == '\0')
				return (begin);
			instr++;
			intof++;
		}
		instr = begin;
		intof = to_find;
		instr++;
	}
	return (0);
}
