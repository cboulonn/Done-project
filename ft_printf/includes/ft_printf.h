/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:04:24 by cboulonn          #+#    #+#             */
/*   Updated: 2016/10/17 15:27:25 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

# define FT_ABS(n)		((n) > 0 ? (n) : -(n))

/*
** flag
*/

# define FLAG_D 1
# define FLAG_0 2
# define FLAG_M 4
# define FLAG_P 8
# define FLAG_E 16

/*
** length modifier
*/

# define LM_H	1
# define LM_L	2
# define LM_J	4
# define LM_Z	8
# define LM_HH	16
# define LM_LL	32

/*
** binary mask
*/

# define BM1_0 0b1100000010000000
# define BM1_1 0b0010000001000000
# define BM2_0 0b111000001000000010000000
# define BM2_1 0b000100000100000001000000
# define BM3_0 0b11110000100000001000000010000000
# define BM3_1 0b00001000010000000100000001000000

typedef struct		s_instr
{
	char			cv_spe;
	int				db_mod;
	int				flags;
	int				width;
	int				point;
	int				prec;
	int				l_mod;
	int				mod_exist;
	int				len;
	int				bt2;
	int				info_nb;
	int				bt3;
}					t_instr;

typedef struct		s_toprint
{
	char			*ret;
	int				i_ret;
	int				mallen;
	int				i_fmt;
	va_list			ap;
}					t_toprint;

/*
** ft_sprintf.c
*/

char				*ft_sprintf(const char *fmt, ...);

/*
** ft_dprintf.c
*/

int					ft_dprintf(int fd, const char *fmt, ...);

/*
** ft_printf.c
*/

int					ft_printf(const char *str, ...);
int					ft_get_instr(t_toprint *save, char *fmt);
char				*ft_cpy_no_malloc(char *dst, const char *fmt,
	t_toprint *save);
int					ft_check_cv_spe(char *str, t_instr *info, t_toprint *save);
int					ft_printf2(t_toprint *save, const char *fmt);

/*
** ft_init.c
*/

t_instr				*ft_init_struct_instr(t_instr *info);
t_toprint			*ft_init_struct_toprint(t_toprint *save);

/*
** ft_parse.c
*/

int					ft_error_ftprintf(t_instr **info);
t_instr				*ft_parse_instr(t_instr *info, t_toprint *save, char *fmt);
t_instr				*ft_reparse_instr(t_instr *info);
void				ft_flags_cv_spe(t_instr *info);
void				ft_flags(t_instr *info);

/*
** ft_instr.c
*/

void				ft_get_flags(t_instr *info, char *fmt, int *i);
void				ft_get_width(t_instr *info, char *fmt, int *i,
	t_toprint *save);
void				ft_get_prec(t_instr *info, char *fmt, int *i,
	t_toprint *save);
void				ft_get_length_mod(t_instr *info, char *fmt, int *i);
void				ft_get_conv_spe(t_instr *info, char *fmt, int *i);

/*
** ft_conv_c.c
*/

int					ft_conv_char(t_instr *info, t_toprint *save);
char				*ft_realloc(t_toprint *save, int len);
void				ft_put_right_place(t_instr *info, t_toprint *save, char c);
void				ft_put_char(t_toprint *save, char c);
void				ft_put_width(t_instr *info, t_toprint *save, int len);

/*
** ft_wildchar.c
*/

int					ft_treatwchar(t_toprint *save, t_instr *info);
char				*ft_get_wchar(int w_int);
int					ft_wchar_len(int w_int);
int					ft_fill_mask(int w_int, int len, int m_0, int m_1);
void				ft_put_right_place_wchar(t_instr *info, t_toprint *save,
	char *w_char);

/*
** ft_conv_str.c
*/

int					ft_conv_str(t_instr *info, t_toprint *save);
void				ft_put_right_place_str(t_instr *info, t_toprint *save,
	char *str);
void				ft_put_right_len(t_toprint *save, t_instr *info, char *str);

/*
** ft_conv_str2.c
*/

void				ft_conv_str_2(t_instr *info, t_toprint *save);

/*
** ft_wildstr.c
*/

int					ft_treatwstr(t_toprint *save, t_instr *info);
int					ft_treatwstr2(t_toprint *save, t_instr *info,
	wchar_t *w_str_fmt, char *w_char);
void				ft_get_wstrlen(t_toprint *save, t_instr *info,
	char *w_char);
void				ft_put_right_place_wstr(t_instr *info, t_toprint *save,
	char *str);
void				ft_put_right_wstrlen(t_toprint *save, char *str,
	int len);

/*
** ft_treat_int.c
*/

void				ft_int_signed(t_instr *info, t_toprint *save);
void				ft_int_unsigned(t_instr *info, t_toprint *save);
char				*ft_get_base(unsigned long nb, t_instr *info);

/*
** ft_put_int.c
*/

void				ft_dispatch_flag(t_instr *info, t_toprint *save,
	char **str);
void				ft_put_right_place_int(t_instr *info, t_toprint *save,
	char **str);
int					ft_put_prec(t_instr *info, t_toprint *save, char **str);
void				ft_put_diese_n_plus(t_instr *info, t_toprint *save,
	char *str);
void				ft_put_int(t_instr *info, t_toprint *save, char **str);

/*
** ft_put_int_2.c
*/

void				ft_put_diese2(t_instr *info, t_toprint *save, char *str);
int					ft_put_moins(char **str, t_instr *info, t_toprint *save);
void				ft_prec(char **str, t_instr *info, t_toprint *save);
void				ft_flag_0_d(char **str, t_instr *info, t_toprint *save);
void				ft_dips_prec_flag_else(char **str, t_instr *info,
	t_toprint *save);
#endif
