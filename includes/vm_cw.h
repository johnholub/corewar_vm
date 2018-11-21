/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cw.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:54:29 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 09:54:29 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_CW_H
# define VM_CW_H

# include "../ft_printf/ft_printf/ft_printf.h"
# include "op.h"
# include <ncurses.h>

# define SIZE_DEC (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)

typedef struct		s_flags
{
	int				v;
	int				dump;
	int				l;
	int				a;
	int				cycle;
}					t_flags;

typedef struct		s_player
{
	t_header		*head;
	int				p_n;
	unsigned char	code[CHAMP_MAX_SIZE + 1];
	int				fd;
	unsigned int	lv_p;
	int				live;
	int				death_oreder;
	int				last_live;
}					t_player;

typedef struct		s_area
{
	unsigned char	val;
	unsigned int	col;
	int				player;
}					t_area;

typedef struct		s_kar
{
	int				reg[16];
	int				p;
	int				pos;
	int				carry;
	int				live;
	int				player;
	unsigned char	com;
	unsigned int	id;
	int				cycles;
	int				d_cycl;
	int				light;
	struct s_kar	*next;
}					t_kar;

typedef struct		s_vis
{
	WINDOW			*win;
}					t_vis;

typedef struct		s_vm
{
	t_player		*p;
	t_area			ar[MEM_SIZE + 1];
	t_kar			*kar;
	t_vis			*vis;
	t_flags			*fl;
	t_kar			*beg;
	int				c_lgh[MEM_SIZE + 1];
	int				speed;
	int				cou_pl;
	int				iter;
	int				ctd;
	int				ch_c;
	int				ctd2;
	int				cycl;
	unsigned int	id_car;
	unsigned int	liv_num;
}					t_vm;

t_flags				*init_flags(void);
t_vm				*init_vm_struct(char **argv, int argc);
void				ft_parse_args(t_flags *fl, t_vm *v, char **argv, int argc);
int					count_corf(char **argv, int argc);
t_kar				*new_car(t_vm *v);
int					is_cor_format(char *str);
int					num_size(int src);
void				vm_grap_pl_infp(t_vm *v);
void				get_magic_head(t_player pl);
void				get_size_of_bot(t_player pl);
void				print_usage(void);
void				exit_prog_err(void);
void				set_players(t_vm *v);
void				begin_game(t_vm *v, t_flags *f);
char				*ft_from16to2(unsigned char num);
t_kar				*ft_operations(t_vm *v, t_kar *car);
t_kar				*ft_ld(t_vm *v, t_kar *car);
t_kar				*ft_st(t_vm *v, t_kar *car);
t_kar				*ft_add(t_vm *v, t_kar *car);
t_kar				*ft_sub(t_vm *v, t_kar *car);
t_kar				*ft_and(t_vm *v, t_kar *car);
int					read_arg_dir(t_vm *v, int i);
short				read_arg_idx(t_vm *v, int i);
void				st_reg_reg(t_kar *car, unsigned char src,
		unsigned char dst);
void				st_reg_idx(t_vm *v, t_kar *car, unsigned int val, int addr);
void				sti_reg_idx(t_vm *v, t_kar *car, unsigned char num, int pl);
void				carry_change(t_kar *car, int i);
void				change_carry_reg(t_kar *car, unsigned char i, int val);
int					is_valid_codage(char *str);
char				*take_fir_arg(char *cod, t_kar *car, t_vm *v);
char				*take_sec_arg(char *cod, t_kar *car, t_vm *v);
void				add_two_arg(char *arg, t_kar *car, t_vm *v, int sp);
char				*ft_add_arr(char *f_arg, char *s_arg);
char				*ft_or_arr(char *f_arg, char *s_arg);
char				*ft_xor_arr(char *f_arg, char *s_arg);
unsigned int		tr_to_ten(char *s);
t_kar				*ft_live(t_vm *v, t_kar *car);
t_kar				*ft_or(t_vm *v, t_kar *car);
t_kar				*ft_xor(t_vm *v, t_kar *car);
t_kar				*ft_zjmp(t_vm *v, t_kar *car);
t_kar				*ft_ldi(t_vm *v, t_kar *car);
t_kar				*ft_sti(t_vm *v, t_kar *car);
t_kar				*ft_fork(t_vm *v, t_kar *car);
t_kar				*ft_lld(t_vm *v, t_kar *car);
t_kar				*ft_lldi(t_vm *v, t_kar *car);
t_kar				*ft_lfork(t_vm *v, t_kar *car);
t_kar				*ft_aff(t_vm *v, t_kar *car);
unsigned int		ft_take_farg(char *cod, t_kar *car, t_vm *v);
unsigned int		ft_take_sarg(char *cod, t_kar *car, t_vm *v);
int					sec_arg_sti(char *cod, t_kar *car, t_vm *v);
int					thr_arg_sti(char *cod, t_kar *car, t_vm *v);
int					sp_size(char *cod);
int					sti_sp_size(char *cod);
void				ft_cr_ncar(t_vm *v, t_kar *car, int pos);
int					find_pl_numb(t_vm *v, int num);
t_kar				*set_op_to_car(t_kar *car, t_vm *v);
int					find_order(t_vm *v);
int					cou_proc(t_kar *car);
int					any_proc_pos(t_kar *car, int j);
void				check_live(t_vm *v);
WINDOW				*create_win(void);
void				set_menu(WINDOW *win, t_vm *v);
void				make_color(WINDOW *win, t_vm *lst, int j);
void				init_visual(t_vm *v, t_flags *f);
void				visual(t_vm *v, t_flags *f, t_area *cmp);
void				free_kkk(char *s1, char *s2);
void				end_vis(t_vm *v, t_flags *f);
void				cw_dump(t_vm *v, t_flags *f);
void				check_proc_lv(t_vm *v);
void				replace_car(t_kar *car, char *cod, int size, int args);
int					m_pos(int pos);
void				print_dump(t_vm *v);
int					check_if_reg(t_vm *v, t_kar *car, char *cod, int sz);
int					is_ex_pl_numb(t_vm *v, int num);
t_area				*create_prev_area(t_area *s1);
int					parse_flags(t_vm *v, t_flags *fl, char **str, int i);
int					did_any_live(t_kar *car);
void				cw_get_winner(t_vm *v);
void				check_ctd(t_vm *v);
void				prco_lv_ctd(t_vm *v);
void				push_button(t_vm *v);
int					arg_is_reg(char *cod, t_kar *car, t_vm *v);
void				set_position(int *x, int *y);
void				exit_from_key(void);
int					get_reg_for_and(t_vm *v, t_kar *car, char *cod);
void				cw_check_def(void);
int					get_win_for_vis(t_vm *v);
void				first_car(t_vm *lst);

#endif
