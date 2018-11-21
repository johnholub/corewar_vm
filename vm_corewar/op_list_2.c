/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:12:02 by yholub            #+#    #+#             */
/*   Updated: 2018/08/28 17:12:02 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

t_kar	*ft_or(t_vm *v, t_kar *car)
{
	char	*cod;
	char	*f_arg;
	char	*s_arg;
	char	*res;
	int		reg;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (is_valid_codage(cod) != 0 && is_valid_codage(cod + 2) != 0
			&& is_valid_codage(cod + 4) == 1)
	{
		f_arg = take_fir_arg(cod, car, v);
		s_arg = take_sec_arg(cod, car, v);
		reg = get_reg_for_and(v, car, cod);
		if (f_arg && s_arg && reg - 1 >= 0 && reg - 1 < 16)
		{
			res = ft_or_arr(f_arg, s_arg);
			add_two_arg(res, car, v, is_valid_codage(cod) +
			is_valid_codage(cod + 2));
			ft_strdel(&res);
		}
		free_kkk(f_arg, s_arg);
	}
	replace_car(car, cod, 4, 3);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_xor(t_vm *v, t_kar *car)
{
	char	*cod;
	char	*f_arg;
	char	*s_arg;
	char	*res;
	int		reg;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (is_valid_codage(cod) != 0 && is_valid_codage(cod + 2) != 0
			&& is_valid_codage(cod + 4) == 1)
	{
		f_arg = take_fir_arg(cod, car, v);
		s_arg = take_sec_arg(cod, car, v);
		reg = get_reg_for_and(v, car, cod);
		if (f_arg && s_arg && reg - 1 >= 0 && reg - 1 < 16)
		{
			res = ft_xor_arr(f_arg, s_arg);
			add_two_arg(res, car, v, is_valid_codage(cod) +
			is_valid_codage(cod + 2));
			ft_strdel(&res);
		}
		free_kkk(f_arg, s_arg);
	}
	replace_car(car, cod, 4, 3);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_zjmp(t_vm *v, t_kar *car)
{
	short step;

	step = (short)(read_arg_idx(v, m_pos(car->pos + 1)) % IDX_MOD);
	if (car->carry == 1)
	{
		step = (short)(car->pos + step);
		if (step < 0)
			step = (short)(step + MEM_SIZE);
		car->pos = step % MEM_SIZE;
	}
	else
		car->pos = m_pos(car->pos + 3);
	return (car);
}

t_kar	*ft_ldi(t_vm *v, t_kar *car)
{
	char			*cod;
	int				fir;
	int				sec;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (is_valid_codage(cod) != 0 &&
			(is_valid_codage(cod + 2) == 1 || is_valid_codage(cod + 2) == 4) &&
			is_valid_codage(cod + 4) == 1)
	{
		fir = ft_take_farg(cod, car, v);
		sec = ft_take_sarg(cod, car, v);
		if (v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1 >= 0 &&
				v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1 < 16 &&
				arg_is_reg(cod, car, v))
		{
			car->reg[v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1] =
					read_arg_dir(v, m_pos(((fir + sec) % IDX_MOD) + car->pos));
		}
	}
	replace_car(car, cod, 2, 3);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_sti(t_vm *v, t_kar *car)
{
	char			*cod;
	int				thr;
	int				sec;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (is_valid_codage(cod) == 1 && is_valid_codage(cod + 2) != 0 &&
			(is_valid_codage(cod + 4) == 1 || is_valid_codage(cod + 4) == 4))
	{
		sec = sec_arg_sti(cod, car, v);
		thr = thr_arg_sti(cod, car, v);
		if (check_if_reg(v, car, cod, sti_sp_size(cod)))
		{
			if (v->ar[m_pos(car->pos + 2)].val - 1 >= 0 &&
					v->ar[m_pos(car->pos + 2)].val - 1 < 16)
			{
				sti_reg_idx(v, car, v->ar[m_pos(car->pos + 2)].val,
						(sec + thr) % IDX_MOD);
			}
		}
	}
	replace_car(car, cod, 2, 3);
	ft_strdel(&cod);
	return (car);
}
