/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:06:50 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/25 15:06:55 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *instr;
	const char *intof;
	const char *begin;

	if (!*little)
		return ((char *)big);
	instr = big;
	intof = little;
	while (*instr)
	{
		begin = instr;
		while (*instr == *intof && *instr && *intof)
		{
			if (intof[1] == '\0')
				return ((char *)begin);
			instr++;
			intof++;
		}
		instr = begin;
		intof = little;
		instr++;
	}
	return (NULL);
}
