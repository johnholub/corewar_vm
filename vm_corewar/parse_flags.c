/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:48:00 by yholub            #+#    #+#             */
/*   Updated: 2018/09/21 10:48:00 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	norm_players_num(t_vm *v)
{
	int i;
	int j;

	i = 0;
	while (i <= v->cou_pl)
	{
		j = 0;
		while (j < i)
		{
			if (v->p[j].p_n == v->p[i].p_n)
			{
				ft_putendl_fd("Error: player number already assigned", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_parse_args(t_flags *fl, t_vm *v, char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		i += parse_flags(v, fl, argv, i);
		i++;
	}
	if (v->cou_pl > 4 || v->cou_pl == 0)
		exit_prog_err();
	norm_players_num(v);
	if (fl->v == 1)
	{
		fl->l = 0;
		fl->a = 0;
		fl->cycle = 0;
		fl->dump = 0;
	}
}
