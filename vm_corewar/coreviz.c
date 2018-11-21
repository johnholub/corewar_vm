/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreviz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:44:07 by yholub            #+#    #+#             */
/*   Updated: 2018/09/11 14:44:08 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	first_car(t_vm *lst)
{
	t_kar	*temp;

	temp = lst->kar;
	while (temp)
	{
		lst->c_lgh[temp->pos] = 1;
		temp = temp->next;
	}
}

void	make_color(WINDOW *win, t_vm *lst, int j)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	if (lst->c_lgh[j] == 1)
		wattron(win, A_STANDOUT);
	else
		wattroff(win, A_STANDOUT);
	if (find_pl_numb(lst, lst->ar[j].player) == 1)
		wattron(win, COLOR_PAIR(1));
	else if (find_pl_numb(lst, lst->ar[j].player) == 2)
		wattron(win, COLOR_PAIR(2));
	else if (find_pl_numb(lst, lst->ar[j].player) == 3)
		wattron(win, COLOR_PAIR(3));
	else if (find_pl_numb(lst, lst->ar[j].player) == 4)
		wattron(win, COLOR_PAIR(4));
}

void	visual2(t_vm *v, t_flags *f)
{
	int		j;
	int		x;
	int		y;

	if (f->v == 0)
		return ;
	j = -1;
	x = 1;
	y = 1;
	first_car(v);
	while (++j < MEM_SIZE)
	{
		make_color(v->vis->win, v, j);
		mvwprintw(v->vis->win, y, x, "%.2x", v->ar[j].val);
		wattroff(v->vis->win, COLOR_PAIR(v->ar[j].player));
		set_position(&x, &y);
		set_menu(v->vis->win, v);
		wattroff(v->vis->win, A_STANDOUT);
	}
	wrefresh(v->vis->win);
}

void	start_button(t_vm *v)
{
	char c;

	if (v->fl->v == 1)
	{
		while (1)
		{
			c = getch();
			if (c == ' ')
				break ;
			if (c == 'q')
			{
				endwin();
				exit(1);
			}
		}
	}
}

void	init_visual(t_vm *v, t_flags *f)
{
	int i;

	if (f->v == 0)
		return ;
	i = -1;
	while (++i < MEM_SIZE)
		v->c_lgh[i] = 0;
	initscr();
	v->vis = (t_vis*)malloc(sizeof(t_vis));
	v->vis->win = create_win();
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	start_color();
	visual2(v, f);
	start_button(v);
}
