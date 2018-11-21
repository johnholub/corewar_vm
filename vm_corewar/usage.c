/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:41:12 by yholub            #+#    #+#             */
/*   Updated: 2018/08/27 12:41:12 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void				cw_ermes(void)
{
	ft_putendl_fd("VM works only with original defines", 2);
	exit(1);
}

void				cw_check_def(void)
{
	if (MEM_SIZE != 4 * 1024)
		cw_ermes();
	else if (IDX_MOD != (4 * 1024) / 8)
		cw_ermes();
	else if (CHAMP_MAX_SIZE != (4 * 1024) / 6)
		cw_ermes();
	else if (CYCLE_TO_DIE != 1536)
		cw_ermes();
	else if (CYCLE_DELTA != 50)
		cw_ermes();
	else if (NBR_LIVE != 21)
		cw_ermes();
	else if (MAX_CHECKS != 10)
		cw_ermes();
	else if (PROG_NAME_LENGTH != 128)
		cw_ermes();
	else if (COMMENT_LENGTH != 2048)
		cw_ermes();
	else if (COREWAR_EXEC_MAGIC != 0xea83f3)
		cw_ermes();
}

void				exit_from_key(void)
{
	endwin();
	exit(1);
}

void				print_usage(void)
{
	ft_printf("Usage: ./corewar [[-n number] champion1.cor] ...\n");
	ft_printf("________________________flags_________________________\n");
	ft_printf("| %-20s %-30s|\n", "-dump <nbr_cycles>",
			"dump memory after nbr_cycles");
	ft_printf("| %-20s %-30s|\n", "-v", "<visualization>");
	ft_printf("| %-20s %-30s|\n", "-a", "<show \"aff\" output>");
	ft_printf("| %-20s %-30s|\n", "-l", "<show lives>");
	ft_printf("|____________________________________________________|\n");
}

void				print_dump(t_vm *v)
{
	int y;
	int x;

	y = 0;
	while (y < MEM_SIZE)
	{
		x = 0;
		if (y == 0)
			ft_printf("0x0000 : ");
		else
			ft_printf("0x%.4x : ", y);
		while (x < 64)
		{
			ft_printf("%.2x ", v->ar[y].val);
			y++;
			x++;
		}
		ft_printf("\n");
	}
}
