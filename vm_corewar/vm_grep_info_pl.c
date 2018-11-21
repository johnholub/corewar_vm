/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_grep_info_pl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:10:15 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 17:10:15 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int		arg_is_reg(char *cod, t_kar *car, t_vm *v)
{
	int j;
	int step;

	j = 0;
	step = 2;
	while (j < 6)
	{
		if (is_valid_codage(cod + j) == 1)
		{
			if (v->ar[m_pos(car->pos + step)].val > 0 &&
			v->ar[m_pos(car->pos + step)].val < 17)
				step++;
			else
				return (0);
		}
		else
			step += 2;
		j += 2;
	}
	return (1);
}

void	printf_info_pl(t_vm *v)
{
	int i;

	i = 0;
	if (v->fl->v == 0)
	{
		ft_printf("Introducing contestants...\n");
		while (i < v->cou_pl)
		{
			ft_printf("* Player %i, weighing %i bytes, "
			"\"%s\" (\"%s\") !\n", i + 1,
					v->p[i].head->prog_size, v->p[i].head->prog_name,
					v->p[i].head->comment);
			i++;
		}
	}
}

void	get_player_infor(t_vm *v, int i)
{
	unsigned int	buff;

	buff = 0;
	get_magic_head(v->p[i]);
	read(v->p[i].fd, &v->p[i].head->prog_name, PROG_NAME_LENGTH);
	read(v->p[i].fd, &buff, 4);
	get_size_of_bot(v->p[i]);
	read(v->p[i].fd, &v->p[i].head->comment, COMMENT_LENGTH);
	read(v->p[i].fd, &buff, 4);
	read(v->p[i].fd, v->p[i].code, v->p[i].head->prog_size);
	if (SIZE_DEC + v->p[i].head->prog_size != lseek(v->p[i].fd, 0, SEEK_END))
	{
		ft_putendl_fd("Size error", 2);
		exit(1);
	}
}

void	vm_grap_pl_infp(t_vm *v)
{
	int i;

	i = 0;
	while (i < v->cou_pl)
	{
		get_player_infor(v, i);
		if (v->p[i].head->prog_size > CHAMP_MAX_SIZE)
		{
			ft_putendl_fd("Specified not valid size", 2);
			exit(1);
		}
		i++;
	}
	printf_info_pl(v);
}
