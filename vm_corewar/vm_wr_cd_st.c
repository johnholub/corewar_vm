/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_wr_cd_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:05:30 by yholub            #+#    #+#             */
/*   Updated: 2018/09/13 15:05:31 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int		check_if_reg(t_vm *v, t_kar *car, char *cod, int sz)
{
	int res;

	res = 0;
	if (is_valid_codage(cod + 2) == 1 && is_valid_codage(cod + 4) == 1 &&
	v->ar[m_pos(car->pos + 3)].val - 1 >= 0 &&
		v->ar[m_pos(car->pos + 3)].val - 1 < 16 &&
		v->ar[m_pos(car->pos + 4)].val - 1 >= 0 &&
				v->ar[m_pos(car->pos + 4)].val - 1 < 16)
		res++;
	else if (is_valid_codage(cod + 2) == 1 && is_valid_codage(cod + 4) != 1 &&
	v->ar[m_pos(car->pos + 3)].val - 1 >= 0 &&
				v->ar[m_pos(car->pos + 3)].val - 1 < 16)
		res++;
	else if (is_valid_codage(cod + 2) != 1 && is_valid_codage(cod + 4) == 1 &&
	v->ar[m_pos(car->pos + sz + 2)].val - 1 >= 0 &&
				v->ar[m_pos(car->pos + sz + 2)].val - 1 < 16)
		res++;
	else if (is_valid_codage(cod + 2) != 1 && is_valid_codage(cod + 4) != 1)
		res++;
	return (res);
}

int		m_pos(int pos)
{
	if (pos >= MEM_SIZE)
		return (pos % MEM_SIZE);
	else if (pos < 0)
		return (pos + MEM_SIZE);
	else
		return (pos);
}

int		is_val_for2(char *str)
{
	if (str[0] == '0' && str[1] == '1')
		return (1);
	else if (str[0] == '1' && str[1] == '1')
		return (2);
	else if (str[0] == '1' && str[1] == '0')
		return (2);
	else
		return (0);
}

void	replace_car(t_kar *car, char *cod, int size, int args)
{
	int replace;

	replace = 0;
	if (args == 3)
	{
		if (size == 4)
			replace = is_valid_codage(cod) +
					is_valid_codage(cod + 2) + is_valid_codage(cod + 4);
		else if (size == 2)
			replace = is_val_for2(cod) + is_val_for2(cod + 2) +
					is_val_for2(cod + 4);
	}
	else if (args == 2)
	{
		if (size == 4)
			replace = is_valid_codage(cod) +
					is_valid_codage(cod + 2);
		else if (size == 2)
			replace = is_val_for2(cod) + is_val_for2(cod + 2);
	}
	car->pos = m_pos(car->pos + replace + 2);
}
