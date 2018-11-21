/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_srtucts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:41:39 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 12:41:39 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

t_flags		*init_flags(void)
{
	t_flags		*res;

	res = (t_flags *)malloc(sizeof(t_flags));
	res->dump = 0;
	res->cycle = 0;
	res->l = 0;
	res->a = 0;
	return (res);
}

t_player	init_player_vm(void)
{
	t_player p;

	p.head = (t_header*)malloc(sizeof(t_header));
	p.live = 0;
	p.last_live = 0;
	p.lv_p = 0;
	p.death_oreder = 0;
	return (p);
}

t_vm		*init_vm_struct(char **argv, int argc)
{
	t_vm	*res;
	int		players;
	int		i;

	i = 0;
	players = count_corf(argv, argc);
	res = (t_vm *)malloc(sizeof(t_vm));
	res->cou_pl = 0;
	res->iter = 0;
	res->ctd = CYCLE_TO_DIE;
	res->ctd2 = CYCLE_TO_DIE;
	res->ch_c = 0;
	res->cycl = 0;
	res->speed = 10;
	res->liv_num = 0;
	res->id_car = 1;
	res->p = (t_player *)malloc(sizeof(t_player) * players);
	while (i < players)
	{
		res->p[i] = init_player_vm();
		i++;
	}
	res->p->p_n = -1;
	return (res);
}
