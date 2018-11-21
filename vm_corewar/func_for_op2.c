/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_op2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:32:29 by yholub            #+#    #+#             */
/*   Updated: 2018/09/04 18:32:30 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void				free_kkk(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

unsigned int		ft_take_farg(char *cod, t_kar *car, t_vm *v)
{
	unsigned int	res;

	if (is_valid_codage(cod) == 1)
	{
		if (v->ar[m_pos(car->pos + 2)].val - 1 >=
		0 && v->ar[m_pos(car->pos + 2)].val - 1 < 16)
		{
			res = (unsigned int)car->reg[v->ar[m_pos(car->pos + 2)].val - 1];
			return (res);
		}
	}
	else if (is_valid_codage(cod) == 2)
	{
		res = read_arg_dir(v, m_pos(car->pos +
				read_arg_idx(v, m_pos(car->pos + 2))) % IDX_MOD);
		return (res);
	}
	else if (is_valid_codage(cod) == 4)
	{
		res = (unsigned int)read_arg_idx(v, m_pos(car->pos + 2));
		return (res);
	}
	return (0);
}

unsigned int		ft_take_sarg(char *cod, t_kar *car, t_vm *v)
{
	unsigned int	res;
	int				sp;

	sp = is_valid_codage(cod);
	if (sp == 4)
		sp -= 2;
	if (is_valid_codage(cod + 2) == 1)
	{
		if (v->ar[m_pos(car->pos + 2 + sp)].val - 1 >= 0 &&
		v->ar[m_pos(car->pos + 2 + sp)].val - 1 < 16)
		{
			res = (unsigned int)
					car->reg[v->ar[m_pos(car->pos + 2 + sp)].val - 1];
			return (res);
		}
	}
	else if (is_valid_codage(cod + 2) == 4)
	{
		res = (unsigned int)read_arg_idx(v, m_pos(car->pos + 2 + sp));
		return (res);
	}
	return (0);
}

int					sp_size(char *cod)
{
	int sp;

	sp = 0;
	if (is_valid_codage(cod) == 4)
	{
		sp = sp + 2;
		if (is_valid_codage(cod + 2) == 4)
		{
			sp = sp + 2;
			return (sp);
		}
		sp = sp + is_valid_codage(cod + 2);
	}
	else if (is_valid_codage(cod) && is_valid_codage(cod) != 4)
	{
		sp = sp + is_valid_codage(cod);
		if (is_valid_codage(cod + 2) == 4)
		{
			sp = sp + 2;
			return (sp);
		}
		sp = sp + is_valid_codage(cod + 2);
	}
	return (sp);
}
