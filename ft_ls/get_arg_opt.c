/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:58:29 by cboulonn          #+#    #+#             */
/*   Updated: 2016/06/17 16:41:39 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_optnarg	*init_list(t_optnarg *getona, int argc)
{
	getona->arg = NULL;
	getona->nb_arg = argc - 1;
	getona->opt = 0;
	getona->button = 0;
	return (getona);
}

t_optnarg	*get_arg_n_opt(int argc, char **argv, char *opt)
{
	t_optnarg	*getona;
	char		res_opt;
	int			i;

	i = 1;
	getona = NULL;
	getona = (t_optnarg *)malloc(sizeof(t_optnarg) * 1);
	if (getona)
	{
		getona = init_list(getona, argc);
		if ((res_opt = get_opt(argv, opt, getona)))
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(res_opt);
			ft_putchar('\n');
			ft_putstr("usage: ft_ls [-lRart] [file ...]\n");
			free(getona);
			return (0);
		}
		get_arg(argv, getona);
	}
	return (getona);
}

void		get_arg(char **argv, t_optnarg *getona)
{
	int		i;
	t_list	*arg;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
		i++;
	while (argv[i])
	{
		arg = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
		ft_lst_push_back(&(getona->arg), arg);
		i++;
	}
}

char		get_opt(char **argv, char *opt, t_optnarg *getona)
{
	int		i;
	int		j;
	char	*ret;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && ft_strchr(opt, argv[i][1]))
	{
		j = 1;
		while (argv[i][j] && (ret = ft_strchr(opt, argv[i][j])))
		{
			getona->opt |= ft_iterative_power(2, (ret - opt));
			j++;
		}
		getona->nb_arg = getona->nb_arg - 1;
		if (ret == NULL)
			return (argv[i][j]);
		i++;
	}
	if (argv[i] && argv[i][0] == '-' && argv[i][1] != '-')
		return (argv[i][1]);
	return (0);
}
