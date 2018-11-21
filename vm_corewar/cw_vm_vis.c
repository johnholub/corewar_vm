/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_vis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:59:15 by yholub            #+#    #+#             */
/*   Updated: 2018/09/19 16:59:15 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int		did_any_live(t_kar *car)
{
	t_kar *temp;

	temp = car;
	while (temp)
	{
		if (temp->live == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	prco_lv_ctd(t_vm *v)
{
	t_kar *temp;

	temp = v->kar;
	while (v->kar)
	{
		if (v->kar->d_cycl == 0)
			v->kar->live = 0;
		v->kar = v->kar->next;
	}
	v->kar = temp;
	v->iter++;
	v->cycl++;
	check_proc_lv(v);
	check_ctd(v);
}

t_area	*create_prev_area(t_area *s1)
{
	t_area	*p;
	int		i;

	i = 0;
	p = (t_area *)malloc(sizeof(t_area) * MEM_SIZE + 1);
	while (i < MEM_SIZE)
	{
		p[i].val = s1[i].val;
		p[i].player = s1[i].player;
		p[i].col = s1[i].col;
		i++;
	}
	return (p);
}
