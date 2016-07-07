/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:08:38 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 16:41:56 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char		*flag_suid(struct stat r, char *right)
{
	if (r.st_mode & S_ISUID)
	{
		if (r.st_mode & S_IXUSR)
			right = ft_strcat(right, "s");
		else
			right = ft_strcat(right, "S");
	}
	else
		(r.st_mode & S_IXUSR) ? ft_strcat(right, "x") : ft_strcat(right, "-");
	return (right);
}

char		*flag_sgid(struct stat r, char *right)
{
	if (r.st_mode & S_ISGID)
	{
		if (r.st_mode & S_IXGRP)
			right = ft_strcat(right, "s");
		else
			right = ft_strcat(right, "S");
	}
	else
		(r.st_mode & S_IXGRP) ? ft_strcat(right, "x") : ft_strcat(right, "-");
	return (right);
}

char		*flag_sticky(struct stat r, char *right)
{
	if (r.st_mode & S_ISVTX)
	{
		if (r.st_mode & S_IXOTH)
			right = ft_strcat(right, "t");
		else
			right = ft_strcat(right, "T");
	}
	else
		(r.st_mode & S_IXOTH) ? ft_strcat(right, "x") :
			ft_strcat(right, "-");
	return (right);
}

char		*ft_get_path_link(char *path, t_info *info)
{
	char	*path_link;

	path_link = NULL;
	path_link = (char *)malloc(sizeof(char) * 256);
	ft_bzero(path_link, 256);
	readlink(path, path_link, 255);
	info->path_lnk = ft_strdup(path_link);
	return (info->path_lnk);
}
