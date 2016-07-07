/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:51:49 by cboulonn          #+#    #+#             */
/*   Updated: 2016/04/24 15:13:21 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 80

typedef struct		s_lst
{
	char			*res_buf;
	int				save_fd;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(int fd, char **line);

#endif
