/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:08:03 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 16:42:08 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_ls	*ft_get_int_length(t_ls *ls, t_info *info)
{
	int		size;
	int		major;
	int		minor;
	int		link;

	link = 0;
	size = 0;
	minor = 0;
	major = 0;
	link = ft_strlen(ft_itoa(info->nb_link));
	size = ft_strlen(ft_itoa(info->size));
	major = ft_strlen(ft_itoa(info->major));
	minor = ft_strlen(ft_itoa(info->minor));
	if (ls->length_link < link)
		ls->length_link = link;
	if (ls->length_size < size)
		ls->length_size = size;
	if (ls->length_major < major)
		ls->length_major = major;
	if (ls->length_minor < minor)
		ls->length_minor = minor;
	return (ls);
}

t_ls	*ft_get_length(t_ls *ls, t_info *info)
{
	int		owner;
	int		grp;
	int		l_time;

	owner = 0;
	grp = 0;
	l_time = 0;
	ls = ft_get_int_length(ls, info);
	owner = ft_strlen(info->owner_name);
	grp = ft_strlen(info->grp_name);
	l_time = ft_strlen(info->last_modif);
	if (ls->length_owner < owner)
		ls->length_owner = owner;
	if (ls->length_grp < grp)
		ls->length_grp = grp;
	if (ls->length_time < l_time)
		ls->length_time = l_time;
	return (ls);
}
