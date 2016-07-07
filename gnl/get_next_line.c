/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:51:25 by cboulonn          #+#    #+#             */
/*   Updated: 2016/04/24 15:12:05 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_list_push_back(t_lst **begin_list, t_lst *data)
{
	t_lst	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = data;
	}
	else
		*begin_list = data;
}

static t_lst	*ft_lstchain(t_lst **begin_list, int fd)
{
	t_lst	*list;
	t_lst	*tmp;

	if (*begin_list == NULL)
	{
		*begin_list = (t_lst *)malloc(sizeof(t_lst));
		(*begin_list)->next = NULL;
		(*begin_list)->res_buf = NULL;
		(*begin_list)->save_fd = fd;
		return (*begin_list);
	}
	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->save_fd == fd)
			return (tmp);
		else
			tmp = tmp->next;
	}
	list = (t_lst *)malloc(sizeof(t_lst));
	list->save_fd = fd;
	list->res_buf = NULL;
	list->next = NULL;
	ft_list_push_back(begin_list, list);
	return (list);
}

static int		ft_printnsave(char *buf_tmp, t_lst *current_buf, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	current_buf->res_buf = ft_strjoin_n_free(current_buf->res_buf, buf_tmp);
	*line = ft_strndup(current_buf->res_buf, '\n');
	while (current_buf->res_buf[i] != '\n' &&
			current_buf->res_buf[i + 1] != '\0')
		i++;
	if ((*line)[i] == '\0' && current_buf->res_buf[i + 1] != '\0')
	{
		tmp = ft_strdup(current_buf->res_buf + i + 1);
		free(current_buf->res_buf);
		current_buf->res_buf = tmp;
	}
	else
	{
		free(current_buf->res_buf);
		current_buf->res_buf = NULL;
	}
	if (buf_tmp)
		free(buf_tmp);
	return (1);
}

static int		ft_catnprint(t_lst *current_buf, char *buf_tmp, int ret,
			char **line)
{
	buf_tmp[ret] = '\0';
	if (ft_strchr(buf_tmp, '\n') == NULL)
		current_buf->res_buf = ft_strjoin_n_free(current_buf->res_buf, buf_tmp);
	if (ft_strchr(buf_tmp, '\n') != NULL)
		return (ft_printnsave(buf_tmp, current_buf, line));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	t_lst			*buf;
	char			*buf_tmp;
	static t_lst	*lst;
	int				ret;

	buf_tmp = NULL;
	if (fd < 0)
		return (-1);
	buf = ft_lstchain(&lst, fd);
	if (buf && buf->res_buf && ft_strchr(buf->res_buf, '\n'))
		return (ft_printnsave(NULL, buf, line));
	buf_tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buf_tmp, BUFF_SIZE)) > 0)
		if (ft_catnprint(buf, buf_tmp, ret, line))
			return (1);
	if (ret == -1)
		return (-1);
	if (buf->res_buf)
	{
		ft_memdel((void **)&buf_tmp);
		return (ft_printnsave(NULL, buf, line));
	}
	if (buf_tmp)
		free(buf_tmp);
	return (0);
}
