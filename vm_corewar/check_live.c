/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:37:41 by yholub            #+#    #+#             */
/*   Updated: 2018/09/10 11:37:42 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void		check_val_rep(t_vm *v)
{
	if (v->ctd2 != v->ctd)
	{
		v->ctd2 = v->ctd;
		v->ch_c = 0;
	}
	else if (v->ctd2 == v->ctd)
		v->ch_c++;
}

int			check_live_calls(t_vm *v)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < v->cou_pl)
	{
		res = res + v->p[i].lv_p;
		i++;
	}
	if (res >= NBR_LIVE)
		return (1);
	return (0);
}

void		check_ctd(t_vm *v)
{
	if (check_live_calls(v) == 1)
	{
		v->ctd = v->ctd - CYCLE_DELTA;
		v->ctd2 = v->ctd;
		v->ch_c = 0;
	}
	else
	{
		check_val_rep(v);
		if (v->ch_c >= MAX_CHECKS)
		{
			v->ctd = v->ctd - CYCLE_DELTA;
			v->ctd2 = v->ctd;
			v->ch_c = 0;
		}
	}
}

void		check_live(t_vm *v)
{
	int		i;

	i = -1;
	check_proc_lv(v);
	check_ctd(v);
	while (++i < v->cou_pl)
	{
		if (v->p[i].live == 1)
			v->p[i].live = 0;
		else if (v->p[i].live == 0)
		{
			v->p[i].death_oreder = find_order(v);
			v->p[i].live = -1;
		}
		v->p[i].lv_p = 0;
	}
	v->iter = 1;
}
