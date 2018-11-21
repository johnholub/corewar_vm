/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:11:55 by yholub            #+#    #+#             */
/*   Updated: 2018/08/28 17:11:56 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

t_kar	*ft_ld(t_vm *v, t_kar *car)
{
	int					val;
	char				*cod;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (cod[0] == '1' && cod[1] == '0' && cod[2] == '0' && cod[3] == '1' &&
	v->ar[m_pos(car->pos + 6)].val > 0 && v->ar[m_pos(car->pos + 6)].val <= 16)
	{
		val = read_arg_dir(v, m_pos(car->pos + 2));
		change_carry_reg(car, v->ar[m_pos(car->pos + 6)].val, val);
	}
	else if (cod[0] == '1' && cod[1] == '1' && cod[2] == '0' && cod[3] == '1' &&
	v->ar[m_pos(car->pos + 4)].val > 0 && v->ar[m_pos(car->pos + 4)].val <= 16)
	{
		val = read_arg_dir(v, m_pos(car->pos +
		(read_arg_idx(v, car->pos + 2) % IDX_MOD)));
		change_carry_reg(car, v->ar[m_pos(car->pos + 4)].val, val);
	}
	replace_car(car, cod, 4, 2);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_st(t_vm *v, t_kar *car)
{
	char				*cod;
	int					val;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (cod[0] == '0' && cod[1] == '1' && cod[2] == '0' && cod[3] == '1' &&
	v->ar[m_pos(car->pos + 2)].val > 0 && v->ar[m_pos(car->pos + 2)].val <= 16
	&& v->ar[m_pos(car->pos + 3)].val > 0 &&
	v->ar[m_pos(car->pos + 3)].val <= 16)
	{
		st_reg_reg(car, v->ar[m_pos(car->pos + 2)].val,
				v->ar[m_pos(car->pos + 3)].val);
	}
	else if (cod[0] == '0' && cod[1] == '1' && cod[2] == '1' && cod[3] == '1' &&
	v->ar[m_pos(car->pos + 2)].val > 0 && v->ar[m_pos(car->pos + 2)].val <= 16)
	{
		val = read_arg_idx(v, car->pos + 3);
		st_reg_idx(v, car, (unsigned int)
		car->reg[v->ar[m_pos(car->pos + 2)].val - 1],
				car->pos + (val % IDX_MOD) + 3);
	}
	replace_car(car, cod, 4, 2);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_add(t_vm *v, t_kar *car)
{
	char	*cod;
	int		reg1;
	int		reg2;
	int		reg3;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	reg1 = v->ar[(car->pos + 2) % MEM_SIZE].val - 1;
	reg2 = v->ar[(car->pos + 3) % MEM_SIZE].val - 1;
	reg3 = v->ar[(car->pos + 4) % MEM_SIZE].val - 1;
	if (cod[0] == '0' && cod[1] == '1' && cod[2] == '0' && cod[3] == '1' &&
			cod[4] == '0' && cod[5] == '1')
	{
		if (reg1 >= 0 && reg1 < 16 && reg2 >= 0 &&
				reg2 < 16 && reg3 >= 0 && reg3 < 16)
		{
			car->reg[reg3] = car->reg[reg1] + car->reg[reg2];
			carry_change(car, car->reg[reg3]);
		}
	}
	replace_car(car, cod, 4, 3);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_sub(t_vm *v, t_kar *car)
{
	char	*cod;
	int		reg1;
	int		reg2;
	int		reg3;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	reg1 = v->ar[(car->pos + 2) % MEM_SIZE].val - 1;
	reg2 = v->ar[(car->pos + 3) % MEM_SIZE].val - 1;
	reg3 = v->ar[(car->pos + 4) % MEM_SIZE].val - 1;
	if (cod[0] == '0' && cod[1] == '1' && cod[2] == '0' && cod[3] == '1' &&
			cod[4] == '0' && cod[5] == '1')
	{
		if (reg1 >= 0 && reg1 < 16 && reg2 >= 0 &&
				reg2 < 16 && reg3 >= 0 && reg3 < 16)
		{
			car->reg[reg3] = car->reg[reg1] - car->reg[reg2];
			carry_change(car, car->reg[reg3]);
		}
	}
	replace_car(car, cod, 4, 3);
	ft_strdel(&cod);
	return (car);
}

t_kar	*ft_and(t_vm *v, t_kar *car)
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
			res = ft_add_arr(f_arg, s_arg);
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
