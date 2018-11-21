/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:43:13 by yholub            #+#    #+#             */
/*   Updated: 2018/09/11 14:43:14 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void		set_menu2(WINDOW *win, int x, int y, t_vm *v)
{
	mvwprintw(win, y + 16, x, "|-----------------------"
							"--------------------------|");
	mvwprintw(win, y + 18, x, "CYCLE: ");
	mvwprintw(win, y + 18, x + 15, "%.4i", v->iter);
	mvwprintw(win, y + 23, x, "CYCLE_TO_DIE: ");
	mvwprintw(win, y + 23, x + 15, "%.4i", v->ctd);
	mvwprintw(win, y + 19, x, "CYCLES_AT_ALL: ");
	mvwprintw(win, y + 19, x + 15, "%.4i", v->cycl);
	mvwprintw(win, y + 21, x, "PROCESSES: ");
	mvwprintw(win, y + 21, x + 15, "%.4i ", cou_proc(v->kar));
	mvwprintw(win, y + 25, x, "NBR_LIVE: ");
	mvwprintw(win, y + 25, x + 15, "%i", NBR_LIVE);
	mvwprintw(win, y + 27, x, "MAX_CHECKS: ");
	mvwprintw(win, y + 27, x + 15, "%i", MAX_CHECKS);
	mvwprintw(v->vis->win, 37, 194, "PRESS \'Q\' "
								"for exit out programm");
	mvwprintw(v->vis->win, 38, 194, "PRESS \'-\' and \'+\' "
								"for changing speed");
	mvwprintw(v->vis->win, 39, 194, "PRESS \'space\' "
								"for start and pause project");
	wattroff(v->vis->win, A_BOLD);
}

void		set_menu(WINDOW *win, t_vm *v)
{
	int		x;
	int		y;
	int		i;

	x = 194;
	y = 1;
	i = 0;
	wattron(v->vis->win, A_BOLD);
	while (i < v->cou_pl)
	{
		mvwprintw(win, y, x, "PLAYER %i :", i + 1);
		mvwprintw(win, y, x + 11, "%s", v->p[i].head->prog_name);
		mvwprintw(win, y + 1, x, "Proces live: ");
		mvwprintw(win, y + 1, x + 13, "%.5i", v->p[i].lv_p);
		y = y + 4;
		i++;
	}
	set_menu2(win, 194, 1, v);
}

WINDOW		*create_win(void)
{
	int		max_y;
	int		max_x;
	WINDOW	*win;

	getmaxyx(stdscr, max_y, max_x);
	win = newwin(max_y - 3, max_x - 2, 1, 1);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
	return (win);
}

void		end_vis(t_vm *v, t_flags *f)
{
	int j;

	j = get_win_for_vis(v);
	if (f->v > 0)
	{
		mvwprintw(v->vis->win, 50, 194, "Contestant %i, \"%s\", has won !\n",
				j + 1, v->p[j].head->prog_name);
		wrefresh(v->vis->win);
		nodelay(stdscr, false);
		getch();
		endwin();
	}
}

void		cw_dump(t_vm *v, t_flags *f)
{
	if (f->dump > 0)
	{
		if (v->cycl == f->cycle)
		{
			if (v->iter == v->ctd && !did_any_live(v->kar))
			{
				check_proc_lv(v);
				cw_get_winner(v);
				exit(1);
			}
			else if (v->iter == v->ctd)
				check_ctd(v);
			print_dump(v);
			exit(1);
		}
	}
}
