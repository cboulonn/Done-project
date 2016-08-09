/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:30:53 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/07 13:55:26 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_error2(char *path)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("Permission denied\n", 2);
}

void	ft_sort_n_disp(t_optnarg *disp_opt)
{
	t_lst_struct	*file;
	DIR				*dir;
	t_ls			*ls;
	t_lst_struct	*act_file;

	file = NULL;
	dir = NULL;
	errno = 0;
	act_file = NULL;
	ls = (t_ls *)malloc(sizeof(t_ls) * 1);
	ls->total = 0;
	if (disp_opt->arg == 0)
	{
		dir = opendir(".");
		if (dir == NULL)
		{
			ft_error(".");
			exit(0);
		}
		ft_readdir(dir, disp_opt->opt, &file, ".");
	}
	else
		ft_isdir(disp_opt, &file, ls, act_file);
	ft_del_list(&file);
}

int		main(int argc, char **argv)
{
	char			*valid_opt;
	t_optnarg		*parse;
	t_list			*tmp;
	int				ret;

	valid_opt = NULL;
	tmp = NULL;
	ret = 0;
	valid_opt = ft_strdup("lRart");
	parse = NULL;
	parse = (t_optnarg *)malloc(sizeof(t_optnarg) * 1);
	parse = get_arg_n_opt(argc, argv, valid_opt);
	if (parse == 0)
		exit(2);
	if (parse->nb_arg != 0)
		ret = ft_parse_error(parse, ret);
	if (ret != -1)
	{
		parse->button = 1;
		ft_sort_n_disp(parse);
	}
	return (0);
}
