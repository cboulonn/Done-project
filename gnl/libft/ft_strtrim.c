/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:56:10 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/29 11:38:00 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ret(char *scpy)
{
	if (scpy == NULL)
		return (ft_strdup(""));
	return (scpy);
}

char			*ft_strtrim(char const *s)
{
	char	*scpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		i++;
		j++;
	}
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i != 0)
	{
		i--;
		j--;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if ((scpy = ft_strnew(j)))
		ft_strncpy(scpy, (char *)(s + i), j);
	return (ft_ret(scpy));
}
