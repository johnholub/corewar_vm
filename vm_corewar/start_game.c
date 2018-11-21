/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:42:19 by yholub            #+#    #+#             */
/*   Updated: 2018/08/28 16:42:19 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	cw_get_winner(t_vm *v)
{
	int		i;
	int		j;
	int		res;

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
	ft_printf("Contestant %i, \"%s\", has won !\n",
			j + 1, v->p[j].head->prog_name);
}

int		cou_proc(t_kar *car)
{
	int		i;
	t_kar	*temp;

	i = 0;
	if (car == NULL)
		return (0);
	temp = car;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_kar	*ft_after_op(t_kar *temp)
{
	temp->com = 0;
	if (temp->pos >= MEM_SIZE)
		temp->pos = temp->pos % MEM_SIZE;
	return (temp);
}

t_kar	*compl_car(t_vm *v)
{
	v->beg = v->kar;
	while (v->kar)
	{
		if (v->kar->com == 0)
			v->kar = set_op_to_car(v->kar, v);
		if (v->kar->cycles == 0)
		{
			v->kar = ft_operations(v, v->kar);
			v->kar = ft_after_op(v->kar);
		}
		if (v->kar->cycles > 0)
			v->kar->cycles--;
		v->kar->d_cycl++;
		v->kar = v->kar->next;
	}
	v->kar = v->beg;
	return (v->kar);
}

void	begin_game(t_vm *v, t_flags *f)
{
	t_area	*cmp;

	init_visual(v, f);
	cmp = create_prev_area(v->ar);
	while (v->ctd > 0 && cou_proc(v->kar))
	{
		push_button(v);
		cw_dump(v, f);
		v->iter++;
		v->cycl++;
		if (v->iter > v->ctd)
			check_live(v);
		if (!cou_proc(v->kar))
			break ;
		visual(v, f, cmp);
		v->kar = compl_car(v);
	}
	if (cou_proc(v->kar))
		prco_lv_ctd(v);
	free(cmp);
	end_vis(v, f);
}
