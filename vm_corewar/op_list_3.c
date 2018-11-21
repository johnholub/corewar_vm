/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:12:07 by yholub            #+#    #+#             */
/*   Updated: 2018/08/28 17:12:07 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

t_kar	*ft_live(t_vm *v, t_kar *car)
{
	int		num;
	int		pl;

	num = read_arg_dir(v, m_pos(car->pos + 1));
	if (is_ex_pl_numb(v, num) == 1)
	{
		pl = find_pl_numb(v, num);
		v->liv_num++;
		v->p[pl - 1].live = 1;
		v->p[pl - 1].last_live = v->liv_num;
		if (v->fl->l == 1)
			ft_printf("A process shows that player %i (%s) is alive\n",
					pl, v->p[pl - 1].head->prog_name);
	}
	car->live = 1;
	car->d_cycl = -1;
	v->p[find_pl_numb(v, car->player) - 1].lv_p++;
	v->p[find_pl_numb(v, car->player) - 1].death_oreder = 0;
	car->pos = m_pos(car->pos + 5);
	return (car);
}

t_kar	*ft_fork(t_vm *v, t_kar *car)
{
	int pos;

	pos = read_arg_idx(v, m_pos(car->pos + 1));
	ft_cr_ncar(v, car, m_pos((pos % IDX_MOD) + car->pos));
	car->pos = m_pos(car->pos + 3);
	return (car);
}

t_kar	*ft_lld(t_vm *v, t_kar *car)
{
	char	*cod;
	int		val;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (cod[0] == '1' && cod[1] == '0' && cod[2] == '0' && cod[3] == '1')
	{
		val = read_arg_dir(v, m_pos(car->pos + 2));
		change_carry_reg(car, v->ar[m_pos(car->pos + 6)].val, val);
	}
	else if (cod[0] == '1' && cod[1] == '1' && cod[2] == '0' && cod[3] == '1')
	{
		val = read_arg_dir(v, m_pos(car->pos +
		read_arg_idx(v, car->pos + 2)));
		change_carry_reg(car, v->ar[m_pos(car->pos + 4)].val, val);
	}
	replace_car(car, cod, 4, 2);
	free(cod);
	return (car);
}

t_kar	*ft_lldi(t_vm *v, t_kar *car)
{
	char			*cod;
	unsigned int	fir;
	unsigned int	sec;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (is_valid_codage(cod) != 0 &&
			(is_valid_codage(cod + 2) == 1 || is_valid_codage(cod + 2) == 4) &&
			is_valid_codage(cod + 4) == 1 && arg_is_reg(cod, car, v))
	{
		fir = ft_take_farg(cod, car, v);
		sec = ft_take_sarg(cod, car, v);
		if (v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1 >= 0 &&
				v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1 < 16)
		{
			car->reg[v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1] =
					read_arg_dir(v, m_pos(((fir + sec)) + car->pos));
			carry_change(car,
				car->reg[v->ar[m_pos(car->pos + 2 + sp_size(cod))].val - 1]);
		}
	}
	replace_car(car, cod, 2, 3);
	free(cod);
	return (car);
}

t_kar	*ft_lfork(t_vm *v, t_kar *car)
{
	short pos;

	pos = read_arg_idx(v, m_pos(car->pos + 1));
	ft_cr_ncar(v, car, m_pos(((pos % MEM_SIZE) + car->pos)));
	car->pos = m_pos(car->pos + 3);
	return (car);
}
