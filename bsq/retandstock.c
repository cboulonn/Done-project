/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retandstock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:04:16 by cboulonn          #+#    #+#             */
/*   Updated: 2016/02/15 17:59:15 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int			onr(char *av, t_struct *s, char *tmp)
{
	int		fd;
	int		ret;

	if (av)
		fd = open(av, O_RDONLY);
	else
		fd = 0;
	s->buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	if (fd < 0)
		ft_free_buf(s);
	while ((ret = read(fd, s->buf, BUF_SIZE)))
	{
		s->buf[ret] = '\0';
		tmp = ft_strjoin_n_free(tmp, s->buf);
	}
	if (!tmp)
		ft_free_buf(s);
	if (s->buf)
		free(s->buf);
	s->buf = tmp;
	ft_get_first_line(s);
	close(fd);
	return (0);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	ft_strcpy(str, s1);
	ft_strcpy(str + len_s1, s2);
	return (str);
}

char		*ft_strcpy(char *dst, char *src)
{
	int compt;

	compt = 0;
	while (src[compt] != '\0')
	{
		dst[compt] = src[compt];
		compt++;
	}
	dst[compt] = src[compt];
	return (dst);
}

char		*ft_strdup(char *s1)
{
	char	*copie;
	int		i;

	i = 0;
	copie = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	while (s1[i] != '\0')
	{
		copie[i] = s1[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}

int			main(int argc, char **argv)
{
	int			i;
	t_struct	*s;

	i = 1;
	if (i < argc)
	{
		while (argv[i])
		{
			s = (t_struct *)malloc(sizeof(t_struct));
			onr(argv[i], s, NULL);
			i++;
		}
	}
	else
	{
		s = (t_struct *)malloc(sizeof(t_struct));
		onr(NULL, s, NULL);
	}
	return (0);
}
