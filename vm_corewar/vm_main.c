/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:49:42 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 09:49:43 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int		main(int argc, char **argv)
{
	t_flags		*fl;
	t_vm		*v;
	int			i;

	i = -1;
	if (argc > 1)
	{
		cw_check_def();
		fl = init_flags();
		v = init_vm_struct(argv, argc);
		ft_parse_args(fl, v, argv, argc);
		v->fl = fl;
		vm_grap_pl_infp(v);
		while (++i < MEM_SIZE)
			v->ar[i].val = 0;
		set_players(v);
		begin_game(v, fl);
		if (v->fl->v == 0)
			cw_get_winner(v);
	}
	else
		print_usage();
	return (0);
}
