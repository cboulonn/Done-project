/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readncheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:35:06 by cboulonn          #+#    #+#             */
/*   Updated: 2016/03/29 18:24:58 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_onr(int fd, t_struct *s, char *tmp)
{
	int		ret;

	s->buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(fd, s->buf, BUF_SIZE)))
	{
		s->buf[ret] = '\0';
		tmp = ft_strjoin_n_free(tmp, s->buf);
	}
	if (!tmp)
	{
		free(s);
		return (write(1, "error\n", 6));
	}
	if (s->buf)
		free(s->buf);
	s->buf = tmp;
	ft_custom_house(s);
	return (0);
}

int		main(int argc, char **argv)
{
	t_struct	*s;
	char		*tmp;
	int			fd;

	tmp = NULL;
	if (argc != 2)
		return (write(1, "usage: ./fillit source_file", 28));
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (write(1, "usage: ./fillit source_file", 28));
		else
		{
			s = (t_struct *)malloc(sizeof(t_struct));
			ft_onr(fd, s, tmp);
		}
	}
	close(fd);
}
