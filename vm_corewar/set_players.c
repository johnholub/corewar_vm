/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:45:35 by yholub            #+#    #+#             */
/*   Updated: 2018/08/27 13:45:35 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

t_kar			*new_car(t_vm *v)
{
	t_kar	*res;
	int		i;

	i = 0;
	res = (t_kar *)malloc(sizeof(t_kar));
	res->player = 0;
	res->p = 0;
	res->carry = 0;
	res->com = 0;
	res->cycles = 0;
	res->live = 0;
	res->id = v->id_car;
	res->pos = 0;
	res->d_cycl = -1;
	res->light = 0;
	res->next = NULL;
	while (i < 16)
	{
		res->reg[i] = 0;
		i++;
	}
	v->id_car++;
	return (res);
}

void			set_carrys(t_vm *v)
{
	int				plus;
	int				i;
	unsigned int	p;
	t_kar			*tmp;

	i = 0;
	p = 0;
	plus = MEM_SIZE / v->cou_pl;
	v->kar = new_car(v);
	while (i < v->cou_pl)
	{
		v->kar->pos = p;
		v->kar->player = v->p[i].p_n;
		v->kar->reg[0] = v->kar->reg[0] + v->p[i].p_n;
		v->kar->com = 0;
		if (i + 1 < v->cou_pl)
		{
			tmp = new_car(v);
			tmp->next = v->kar;
			v->kar = tmp;
		}
		i++;
		p = p + plus;
	}
}

void			set_player(t_vm *v, int i, int pl)
{
	int k;

	k = 0;
	while (k < (int)v->p[pl].head->prog_size)
	{
		v->ar[i].val = v->p[pl].code[k];
		v->ar[i].player = v->p[pl].p_n;
		k++;
		i++;
	}
}

void			set_players(t_vm *v)
{
	int		i;
	int		j;
	int		plus;

	i = 0;
	j = 0;
	if (v->cou_pl >= 1 && v->cou_pl <= 4)
	{
		plus = MEM_SIZE / v->cou_pl;
		while (j < v->cou_pl)
		{
			set_player(v, i, j);
			j++;
			i += plus;
		}
	}
	set_carrys(v);
}
