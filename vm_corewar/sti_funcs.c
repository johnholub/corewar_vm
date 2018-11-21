/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:44:36 by yholub            #+#    #+#             */
/*   Updated: 2018/09/05 13:44:37 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int					find_pl_numb(t_vm *v, int num)
{
	int i;

	i = 0;
	while (i < v->cou_pl)
	{
		if (v->p[i].p_n == num)
			return (i + 1);
		i++;
	}
	return (0);
}

int					sec_arg_sti(char *cod, t_kar *car, t_vm *v)
{
	int res;

	if (is_valid_codage(cod + 2) == 1)
	{
		if (v->ar[m_pos(car->pos + 3)].val - 1 >= 0 &&
		v->ar[m_pos(car->pos + 3)].val - 1 < 16)
		{
			res = (unsigned int)car->reg[v->ar[m_pos(car->pos + 3)].val - 1];
			return (res);
		}
	}
	else if (is_valid_codage(cod + 2) == 2)
	{
		res = read_arg_dir(v, m_pos(car->pos +
				read_arg_idx(v, m_pos(car->pos + 3))) % IDX_MOD);
		return (res);
	}
	else if (is_valid_codage(cod + 2) == 4)
	{
		res = read_arg_idx(v, m_pos(car->pos + 3));
		return (res);
	}
	return (0);
}

int					thr_arg_sti(char *cod, t_kar *car, t_vm *v)
{
	int				res;
	int				sp;

	sp = is_valid_codage(cod + 2);
	if (sp == 4)
		sp -= 2;
	if (is_valid_codage(cod + 4) == 1)
	{
		if (v->ar[m_pos(car->pos + 3 + sp)].val - 1 >= 0 &&
		v->ar[m_pos(car->pos + 3 + sp)].val - 1 < 16)
		{
			res = car->reg[v->ar[m_pos(car->pos + 3 + sp)].val - 1];
			return (res);
		}
	}
	else if (is_valid_codage(cod + 4) == 4)
	{
		res = read_arg_idx(v, m_pos(car->pos + 3 + sp));
		return (res);
	}
	return (0);
}

int					sti_sp_size(char *cod)
{
	int sp;

	sp = 0;
	if (is_valid_codage(cod + 4) == 4)
	{
		sp = sp + 2;
		if (is_valid_codage(cod + 2) == 4)
		{
			sp = sp + 2;
			return (sp);
		}
		sp = sp + is_valid_codage(cod + 2);
	}
	else if (is_valid_codage(cod + 4) && is_valid_codage(cod + 4) != 4)
	{
		sp = sp + is_valid_codage(cod + 4);
		if (is_valid_codage(cod + 2) == 4)
		{
			sp = sp + 2;
			return (sp);
		}
		sp = sp + is_valid_codage(cod + 2);
	}
	return (sp);
}

void				ft_cr_ncar(t_vm *v, t_kar *car, int pos)
{
	t_kar	*temp;
	int		i;

	i = 0;
	temp = new_car(v);
	temp->next = v->beg;
	while (i < 16)
	{
		temp->reg[i] = car->reg[i];
		i++;
	}
	temp->pos = pos;
	temp->carry = car->carry;
	temp->live = car->live;
	temp->player = car->player;
	temp->com = 0;
	temp->d_cycl = car->d_cycl + 1;
	temp->cycles = 0;
	v->beg = temp;
}
