/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbougero <lbougero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 16:38:56 by lbougero          #+#    #+#             */
/*   Updated: 2016/03/03 16:53:26 by lbougero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*cpy;

	len = 0;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len++;
	i = len;
	if (s[len] == '\0')
		return (ft_strdup(""));
	while (s[len] != '\0')
		len++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
		&& len != 0)
		--len;
	len++;
	if ((cpy = ft_strnew(len - i)))
		return (ft_strncpy(cpy, (char *)s + i, len - i));
	return (NULL);
}
