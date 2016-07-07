/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:13:48 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/08 13:23:38 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	get_info_uid(struct stat file_info, t_info *info)
{
	struct passwd	*info_uid;

	info_uid = getpwuid(file_info.st_uid);
	if (info_uid != NULL)
		info->owner_name = ft_strdup(info_uid->pw_name);
	else
		info->owner_name = ft_itoa(file_info.st_uid);
}

void	get_info_grp(struct stat file_info, t_info *info)
{
	struct group	*grp;

	grp = getgrgid(file_info.st_gid);
	if (grp != NULL)
		info->grp_name = ft_strdup(grp->gr_name);
	else
		info->grp_name = ft_itoa(file_info.st_uid);
}

void	get_major_minor(struct stat file_info, t_info *info)
{
	info->major = major(file_info.st_rdev);
	info->minor = minor(file_info.st_rdev);
}

void	get_other(char *name, t_info *info, struct stat file_info)
{
	info->right = ft_get_right(file_info);
	info->nb_link = file_info.st_nlink;
	info->last_modif = ft_get_time(file_info, info->time_sec, info);
	info->file_name = ft_strdup(name);
	info->block = file_info.st_blocks;
}

char	*get_futur_time(long temps, char *timelapse)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strsub(ctime(&temps), 19, 5);
	tmp = ft_strsub(ctime(&temps), 4, 7);
	timelapse = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp);
	return (timelapse);
}
