/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:31:20 by yholub            #+#    #+#             */
/*   Updated: 2018/08/29 15:31:20 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	st_reg_idx(t_vm *v, t_kar *car, unsigned int val, int addr)
{
	char i;

	i = 4;
	while (i--)
	{
		v->ar[m_pos(addr)].player = car->player;
		v->ar[m_pos(addr--)].val = val & 0xFF;
		val >>= 8;
	}
}

void	sti_reg_idx(t_vm *v, t_kar *car, unsigned char num, int pl)
{
	int				val;
	int				i;
	int				p;

	if (num - 1 >= 0 && num - 1 < 16)
	{
		i = 4;
		val = car->reg[num - 1];
		p = car->pos + pl + 3;
		while (i--)
		{
			v->ar[m_pos(p)].player = car->player;
			v->ar[m_pos(p--)].val = val & 0xFF;
			val >>= 8;
		}
	}
}

int		get_win_for_vis(t_vm *v)
{
	int i;
	int j;
	int res;

	res = 0;
	i = -1;
	j = 0;
	if (v->liv_num > 0)
	{
		while (++i < v->cou_pl)
			if (v->p[i].last_live >= res)
			{
				res = v->p[i].last_live;
				j = i;
			}
	}
	else
		while (++i < v->cou_pl)
			if (v->p[i].death_oreder >= res)
			{
				res = v->p[i].death_oreder;
				j = i;
			}
	return (j);
}
