/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:37:20 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/25 16:14:33 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_len(char *line, t_istruct *length)
{
	int			*tab;
	t_list		*lst;

	tab = NULL;
	lst = NULL;
	length->len = ft_len_without_spaces(line);
	if (length->save == 0)
		length->save = length->len;
	if (length->len != length->save)
		return (-1);
	return (1);
}

int		ft_len_without_spaces(char *line)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (line[c] != '\0')
	{
		if (line[c] != ' ')
			c++;
		else
		{
			i++;
			while (line[c] == ' ')
				c++;
		}
	}
	if (line[c] == '\0' && line[c - 1] != ' ')
		i++;
	return (i);
}

int		ft_check_error(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '-' && line[i] != ' ' && (line[i] < 48 || line[i] > 57))
			return (-1);
		i++;
	}
	return (1);
}

int		ft_parse_fdf(int fd, char *line, int ret)
{
	int			*tab;
	t_istruct	*length;
	t_mlx		*mlst;
	size_t		i;

	mlst = ft_init_mlx(&length, &tab, &i);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((length->check = ft_check_error(line)) == 1)
		{
			if ((length->res = ft_check_len(line, length)) == 1)
				ft_create_mlst(mlst, length, tab, line);
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (ret == -1 || length->len == 0)
		return (-1);
	ft_link_adresses(mlst, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;
	int		res;
	int		i;

	line = NULL;
	res = 0;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (write(2, "usage: ./fdf [file]\n", 20));
		if ((ret = ft_parse_fdf(fd, line, res)) != -1)
			;
		else
			return (write(2, "map error\n", 10));
	}
	else
		return (write(2, "usage: ./fdf [file]\n", 20));
}
