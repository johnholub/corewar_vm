/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 17:44:13 by yholub            #+#    #+#             */
/*   Updated: 2018/09/22 17:44:13 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	set_position(int *x, int *y)
{
	*x += 3;
	if (*x == 193)
	{
		*x = 1;
		(*y)++;
	}
}

void	button_wait(t_vm *v)
{
	char c2;

	while (1)
	{
		c2 = getch();
		mvwprintw(v->vis->win, 35, 194, "PAUSE: ON ");
		wrefresh(v->vis->win);
		if (c2 == ' ')
			break ;
		if (c2 == 'q')
		{
			endwin();
			exit(1);
		}
	}
}

void	button_func(int time, t_vm *v, int speed)
{
	usleep(time);
	mvwprintw(v->vis->win, 33, 194, "SPEED NOW: %d", speed);
	mvwprintw(v->vis->win, 35, 194, "PAUSE: OFF");
}

void	button_exept(t_vm *v)
{
	wattroff(v->vis->win, A_BOLD);
	wrefresh(v->vis->win);
}

void	push_button(t_vm *v)
{
	static int	time;
	char		c;

	if (v->fl->v == 1)
	{
		c = getch();
		wattron(v->vis->win, A_BOLD);
		if (c == ' ')
			button_wait(v);
		else if (c == 'q')
			exit_from_key();
		if (c == '+')
			if (time != 0 && ((time -= 10000) || 1) && ((v->speed += 1) || 1))
				;
		if (c == '-')
			if (time != 90000 && ((time += 10000) || 1) &&
			((v->speed -= 1) || 1))
				;
		button_func(time, v, v->speed);
		if (v->speed < 10)
			mvwprintw(v->vis->win, 33, 194, "SPEED NOW: %d ", v->speed);
		button_exept(v);
	}
}
