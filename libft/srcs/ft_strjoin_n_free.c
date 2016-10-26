/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:15:07 by cboulonn          #+#    #+#             */
/*   Updated: 2016/09/05 13:09:31 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_n_free(char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1)
		free((char *)s1);
	return (res);
}
