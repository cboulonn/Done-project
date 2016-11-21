/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:19:54 by cboulonn          #+#    #+#             */
/*   Updated: 2016/09/01 17:40:11 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char		*ft_get_type(struct stat r, char *act_right)
{
	if (S_ISDIR(r.st_mode))
		act_right = ft_strcat(act_right, "d");
	else if (S_ISREG(r.st_mode))
		act_right = ft_strcat(act_right, "-");
	else if (S_ISBLK(r.st_mode))
		act_right = ft_strcat(act_right, "b");
	else if (S_ISCHR(r.st_mode))
		act_right = ft_strcat(act_right, "c");
	else if (S_ISLNK(r.st_mode))
		act_right = ft_strcat(act_right, "l");
	else if (S_ISSOCK(r.st_mode))
		act_right = ft_strcat(act_right, "s");
	else if (S_ISFIFO(r.st_mode))
		act_right = ft_strcat(act_right, "p");
	return (act_right);
}

char		*ft_get_right(struct stat r)
{
	char	*right;

	right = NULL;
	right = ft_strnew(10);
	right = ft_get_type(r, right);
	(r.st_mode & S_IRUSR) ? ft_strcat(right, "r") : ft_strcat(right, "-");
	(r.st_mode & S_IWUSR) ? ft_strcat(right, "w") : ft_strcat(right, "-");
	right = flag_suid(r, right);
	(r.st_mode & S_IRGRP) ? ft_strcat(right, "r") : ft_strcat(right, "-");
	(r.st_mode & S_IWGRP) ? ft_strcat(right, "w") : ft_strcat(right, "-");
	right = flag_sgid(r, right);
	(r.st_mode & S_IROTH) ? ft_strcat(right, "r") : ft_strcat(right, "-");
	(r.st_mode & S_IWOTH) ? ft_strcat(right, "w") : ft_strcat(right, "-");
	right = flag_sticky(r, right);
	return (right);
}

char		*ft_get_time(struct stat actual_time, long temps, t_info *info)
{
	char	*timelapse;
	long	act_time;

	temps = actual_time.st_mtimespec.tv_sec;
	act_time = time(NULL);
	timelapse = NULL;
	if (temps < act_time - 15778800 || temps > act_time)
		timelapse = get_futur_time(temps, timelapse);
	else
		timelapse = ft_strsub(ctime(&temps), 4, 12);
	info->time_sec = actual_time.st_mtimespec.tv_sec;
	info->time_nsec = actual_time.st_mtimespec.tv_nsec;
	return (timelapse);
}

char		*init_get_info(char *path, t_info *info, char *name, char *s)
{
	path ? path = ft_strjoin(path, "/") : 0;
	s = ft_strjoin(path, name);
	info->path = path;
	return (s);
}

t_info		*ft_get_info(char *name, char *path, int opt)
{
	struct stat		file_info;
	t_info			*info;
	char			*s;

	info = (t_info *)malloc(sizeof(t_info));
	init_list_info(info, NULL);
	s = NULL;
	s = init_get_info(path, info, name, s);
	info->opt = opt;
	if (lstat(s, &file_info) == -1)
	{
		ft_error(name);
		return (NULL);
	}
	get_info_uid(file_info, info);
	get_info_grp(file_info, info);
	if ((S_ISBLK(file_info.st_mode)) || (S_ISCHR(file_info.st_mode)))
		get_major_minor(file_info, info);
	else
		info->size = file_info.st_size;
	if ((S_ISLNK(file_info.st_mode)))
		info->path_lnk = ft_get_path_link(s, info);
	get_other(name, info, file_info);
	return (info);
}
