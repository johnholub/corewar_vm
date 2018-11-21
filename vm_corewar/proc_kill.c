/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:33:08 by yholub            #+#    #+#             */
/*   Updated: 2018/09/12 13:33:09 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

t_kar	*is_first(t_kar *car)
{
	t_kar *tmp;

	tmp = car;
	if (car->next)
		car = car->next;
	else
		car = NULL;
	free(tmp);
	return (car);
}

t_kar	*is_not_first(t_kar *fir, t_kar *car)
{
	t_kar *temp;
	t_kar *del;

	temp = fir;
	while (temp->next != car)
		temp = temp->next;
	del = temp->next;
	if (!temp->next->next)
		temp->next = NULL;
	else
		temp->next = temp->next->next;
	del->next = NULL;
	free(del);
	temp = fir;
	return (temp);
}

void	change_live_val(t_vm *v)
{
	t_kar *beg;

	beg = v->kar;
	while (v->kar)
	{
		if (v->kar->live > 0)
			v->kar->live = 0;
		v->kar = v->kar->next;
	}
	v->kar = beg;
}

void	check_proc_lv(t_vm *v)
{
	t_kar	*beg;

	beg = v->kar;
	while (v->kar)
	{
		if (v->kar->live == 0)
		{
			if (beg == v->kar)
			{
				v->kar = is_first(v->kar);
				beg = v->kar;
			}
			else
				v->kar = is_not_first(beg, v->kar);
		}
		else
			v->kar = v->kar->next;
	}
	v->kar = beg;
	change_live_val(v);
}
