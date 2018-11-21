/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:14:08 by yholub            #+#    #+#             */
/*   Updated: 2018/09/24 16:14:08 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	visual_case1(t_vm *v, int j, int x, int y)
{
	v->ar[j].col = 200;
	wattroff(v->vis->win, A_STANDOUT);
	make_color(v->vis->win, v, j);
	mvwprintw(v->vis->win, y, x, "%.2x", v->ar[j].val);
	wattroff(v->vis->win, COLOR_PAIR(v->ar[j].player));
}

void	visual_case2(t_vm *v, int j, int x, int y)
{
	make_color(v->vis->win, v, j);
	mvwprintw(v->vis->win, y, x, "%.2x", v->ar[j].val);
	wattroff(v->vis->win, COLOR_PAIR(v->ar[j].player));
	wattroff(v->vis->win, A_STANDOUT);
}

void	visual_case3(t_vm *v, int j, int x, int y)
{
	wattron(v->vis->win, A_BOLD);
	mvwprintw(v->vis->win, y, x, "%.2x", v->ar[j].val);
	v->ar[j].col--;
}

void	cycle_visual(t_vm *v, t_area *cmp)
{
	int		j;
	int		x;
	int		y;

	j = -1;
	x = 1;
	y = 1;
	while (++j < MEM_SIZE)
	{
		if (v->ar[j].col > 0)
			visual_case3(v, j, x, y);
		if (cmp[j].val != v->ar[j].val)
		{
			visual_case1(v, j, x, y);
			cmp[j].val = v->ar[j].val;
		}
		else
			visual_case2(v, j, x, y);
		wattroff(v->vis->win, A_BOLD);
		set_position(&x, &y);
	}
}

void	visual(t_vm *v, t_flags *f, t_area *cmp)
{
	t_kar	*temp;
	int		i;

	i = -1;
	if (f->v == 0)
		return ;
	while (++i < MEM_SIZE)
		v->c_lgh[i] = 0;
	first_car(v);
	make_color(v->vis->win, v, -1);
	mvwprintw(v->vis->win, 1, 1, "%.2x", v->ar[-1].val);
	wattroff(v->vis->win, COLOR_PAIR(v->ar[-1].player));
	cycle_visual(v, cmp);
	set_menu(v->vis->win, v);
	wrefresh(v->vis->win);
	temp = v->kar;
	while (temp)
	{
		temp->light = 0;
		temp = temp->next;
	}
}
