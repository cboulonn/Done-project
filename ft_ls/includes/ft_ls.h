/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboulonn <cboulonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:59:03 by cboulonn          #+#    #+#             */
/*   Updated: 2016/07/07 14:03:20 by cboulonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libc.h>
# include <dirent.h>
# include <unistd.h>
# include <stdio.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <libft.h>
# include <errno.h>

# define OPT_L	1
# define OPT_RECURS	2
# define OPT_A	4
# define OPT_R	8
# define OPT_T	16

typedef struct				s_ls
{
	int						total;
	int						toprint;
	int						length_link;
	int						length_owner;
	int						length_grp;
	int						length_major;
	int						length_minor;
	int						length_size;
	int						length_time;
	int						button;
}							t_ls;

typedef struct				s_lst_struct
{
	struct s_lst_struct		*next;
	struct s_info			*file;
	struct s_lst_struct		*recurs;
}							t_lst_struct;

typedef struct				s_info
{
	char					*file_name;
	char					*owner_name;
	char					*grp_name;
	char					*last_modif;
	long					time_sec;
	long					time_nsec;
	char					*right;
	int						size;
	int						major;
	int						minor;
	int						nb_link;
	int						opt;
	char					*path_lnk;
	int						block;
	char					*path;
}							t_info;

typedef struct				s_optnarg
{
	t_list					*arg;
	int						nb_arg;
	int						opt;
	int						button;
}							t_optnarg;

t_optnarg					*get_arg_n_opt(int argc, char **argv, char *opt);
char						get_opt(char **argv, char *opt, t_optnarg *getona);
void						get_arg(char **argv, t_optnarg *getona);
void						ft_sort_n_disp(t_optnarg *disp_opt);
void						disp_opt_list(t_list **arg, int opt);
void						ft_readdir(DIR *dir, int opt, t_lst_struct **beg,
	char *path);
void						ft_readdir2(t_ls *ls, t_info *info,
	t_lst_struct *act_file, t_lst_struct **beg);
void						ft_error2(char *path);
void						ft_isdir(t_optnarg *disp_arg, t_lst_struct **t_file,
	t_ls *ls, t_lst_struct *act_file);
void						ft_isdirsec(t_optnarg *disp_arg, char *name,
	DIR *dir, t_lst_struct *act_file);
void						ft_isdir3(t_optnarg *disp_arg, char *name, DIR *dir,
	t_lst_struct *act_file);
void						ft_readfile(t_ls *ls, t_info *info,
	t_lst_struct *act_file, t_lst_struct **t_file);
t_ls						*init_list_ls(t_ls *ls);
void						print_dir_name(char *content);
t_info						*ft_get_info(char *name, char *path, int opt);
t_info						*init_list_info(t_info *lst, t_optnarg *disp_opt);
void						ft_error(char *content);
char						*ft_get_right(struct stat r);
char						*ft_get_type(struct stat r, char *act_right);
char						*flag_suid(struct stat r, char *right);
char						*flag_sgid(struct stat r, char *right);
char						*flag_sticky(struct stat r, char *right);
void						get_info_uid(struct stat file_info, t_info *info);
void						get_info_grp(struct stat file_info, t_info *info);
void						get_major_minor(struct stat file_info,
	t_info *info);
char						*ft_get_time(struct stat actual_time, long temps,
	t_info *info);
char						*get_futur_time(long temps, char *timelapse);
char						*ft_get_path_link(char *path, t_info *info);
void						get_other(char *name, t_info *info,
	struct stat file_info);
t_ls						*ft_get_length(t_ls *ls, t_info *info);
t_ls						*ft_get_int_length(t_ls *ls, t_info *info);
t_lst_struct				*init_list_struct(void);
void						sort_list(t_lst_struct **lst,
	t_lst_struct *act_file);
int							ft_cmp_alpha_n_time(t_lst_struct *prev,
	t_info *info);
void						disp_opt(t_lst_struct **lst, t_info *info,
	t_ls *ls);
void						sort_reverse(t_lst_struct **lst);
void						print_opt_l(t_lst_struct *lst, t_ls *ls);
void						print_total(t_ls *ls);
void						ft_put_spaces_char(char *info, int len_max);
void						print_spaces(t_lst_struct *lst, t_ls *ls);
void						ft_put_spaces_int(int info, int len_max);
void						ft_put_spaces_major(int info, int len_max);
void						print_link(char *link);
void						print_name(t_lst_struct *lst);
void						ft_recurs(t_lst_struct *lst, t_info *info);
void						print_path(char *path);
void						ft_del_list(t_lst_struct **file);
void						ft_del_l_one(t_list **file);
t_list						*ft_sort(t_optnarg *disp_arg, t_info *info,
	t_info *info2, t_list *tmp);
void						ft_sort_list(t_optnarg *disp_arg, DIR *dir);
int							ft_cmp_alpha_n_time2(t_info *info, t_info *info2,
	t_list *tmp);
void						sort_reverse_list(t_list **list);
void						ft_sorting(t_optnarg *disp_arg, t_list *tmp);
void						ft_swap2(t_list **tmp, t_list **tmp2);
int							ft_cmp(int a, int b);
int							ft_idontknow(t_optnarg *disp_arg, t_list *tmp);
void						ft_sort_arg_rep(t_optnarg *disp_arg, DIR *dir);
t_list						*ft_sort2(t_optnarg *disp_arg, int a, int b,
	t_list *tmp);
int							ft_parse_error(t_optnarg *lst_arg, int i);
t_list						*ft_places(t_list *tmp, t_ls *ls,
	t_optnarg *disp_arg);
void						ft_b(t_ls *ls, t_lst_struct **t_file,
	t_lst_struct *act_file, t_info *info);
void						ft_c(t_info *info, t_ls *ls, t_lst_struct *act_file,
	t_lst_struct **beg);
int							ft_d(t_lst_struct **tmp, t_info *info, char **path);

#endif
