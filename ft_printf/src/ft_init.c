/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:33:38 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/12 16:35:27 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_instr		*ft_init_struct_instr(t_instr *info)
{
	info = (t_instr *)malloc(sizeof(t_instr));
	info->cv_spe = 0;
	info->db_mod = 0;
	info->flags = 0;
	info->width = 0;
	info->point = 0;
	info->prec = 0;
	info->l_mod = 0;
	info->mod_exist = 0;
	info->len = 0;
	info->bt2 = 0;
	info->info_nb = -1;
	info->bt3 = 0;
	return (info);
}

t_toprint	*ft_init_struct_toprint(t_toprint *save)
{
	save = (t_toprint *)malloc(sizeof(t_toprint));
	save->ret = NULL;
	save->i_ret = 0;
	save->mallen = 1000;
	save->i_fmt = 0;
	return (save);
}
