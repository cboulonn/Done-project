/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:02:18 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/25 16:48:57 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"

typedef struct	s_istruct
{
	int			check;
	int			len;
	int			save;
	int			res;
}				t_istruct;

typedef struct	s_mlx
{
	t_list		*beg;
	t_list		*lst;
	void		*mlx;
	void		*win;
	void		*img;
	int			i;
	int			heigth;
	int			width;
	int			t_h;
	int			t_w;
	char		*ptr_img;
	char		*ptr_img2;
	int			bpp;
	int			sizel;
	int			endian;
	int			color;
	int			bt_d;
	float		zoom;
	float		alt;
	float		dpl1;
	float		dpl2;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			rev;
	int			line;
}				t_mlx;

int				ft_parse_fdf(int fd, char *line, int ret);
int				ft_check_error(char *line);
int				ft_len_without_spaces(char *line);
int				ft_check_len(char *line, t_istruct *length);
t_istruct		*ft_init_i_struct(t_istruct *length);
int				*ft_strsplint(char *s, char c);
void			h_lines(t_mlx *mlst);
void			v_lines(t_mlx *mlst);
void			ft_link_adresses(t_mlx *mlst, int bt);
void			ft_set_pos(t_mlx *mlst, t_list *lst, int button, int i);
void			ft_what_lines(t_mlx *mlst, int i);
void			ft_cor_1(t_mlx *mlst, int i, int j, int *tab);
void			ft_cor_2(t_mlx *mlst, int i, int j, int *tab);
void			ft_cor_2_bis(t_mlx *mlst, int i, int j, int *tab2);
t_mlx			*ft_init_mlx(t_istruct **length, int **tab, size_t *i);
void			ft_create_mlst(t_mlx *mlst, t_istruct *length, int *tab,
	char *line);
void			ft_clear_n_create(t_mlx *mlst);
void			ft_key_code(int keycode, t_mlx *mlst);
void			ft_key_code_color(t_mlx *mlst);
void			ft_keycode_suite(int keycode, t_mlx *mlst);
void			ft_window_to_image(t_mlx *mlst);
void			ft_link_adresses_suite(t_mlx *mlst, int bt, int *j);
int				ft_mouse_hook(int button, int x, int y, t_mlx *mlst);

#endif
