/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:27:52 by yholub            #+#    #+#             */
/*   Updated: 2018/09/06 12:27:52 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int		find_order(t_vm *v)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < v->cou_pl)
	{
		if (res < v->p[i].death_oreder)
			res = v->p[i].death_oreder;
		i++;
	}
	return (res + 1);
}

int		any_proc_pos(t_kar *car, int j)
{
	t_kar *temp;

	temp = car;
	while (temp)
	{
		if (temp->pos == j)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		get_cycle_for_op2(int op)
{
	if (op == 11)
		return (25);
	else if (op == 12)
		return (800);
	else if (op == 13)
		return (10);
	else if (op == 14)
		return (50);
	else if (op == 15)
		return (1000);
	else if (op == 16)
		return (2);
	else
		return (0);
}

int		get_cycle_for_op(int op)
{
	if (op == 1)
		return (10);
	else if (op == 2)
		return (5);
	else if (op == 3)
		return (5);
	else if (op == 4)
		return (10);
	else if (op == 5)
		return (10);
	else if (op == 6)
		return (6);
	else if (op == 7)
		return (6);
	else if (op == 8)
		return (6);
	else if (op == 9)
		return (20);
	else if (op == 10)
		return (25);
	else
		return (get_cycle_for_op2(op));
}

t_kar	*set_op_to_car(t_kar *car, t_vm *v)
{
	if (v->ar[car->pos].val > 0 && v->ar[car->pos].val < 17)
	{
		car->com = v->ar[car->pos].val;
		car->p = v->ar[car->pos].player;
		car->cycles = get_cycle_for_op(v->ar[car->pos].val) - 1;
	}
	else
	{
		car->com = 200;
		car->cycles = 0;
	}
	return (car);
}
