/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:02:44 by yholub            #+#    #+#             */
/*   Updated: 2018/09/24 16:48:36 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

char	*tr_to_bin(unsigned int num)
{
	char				*str;
	long long			div;
	int					i;

	div = 4096;
	div = div * (4096 * 128);
	i = -1;
	str = ft_strnew(32);
	while (++i < 32 && div != 0)
	{
		if (div <= num)
		{
			str[i] = '1';
			num = num % div;
		}
		else
			str[i] = '0';
		div = div / 2;
	}
	return (str);
}

int		is_valid_codage(char *str)
{
	if (str[0] == '0' && str[1] == '1')
		return (1);
	else if (str[0] == '1' && str[1] == '1')
		return (2);
	else if (str[0] == '1' && str[1] == '0')
		return (4);
	else
		return (0);
}

char	*take_fir_arg(char *cod, t_kar *car, t_vm *v)
{
	char *res;

	if (is_valid_codage(cod) == 1)
	{
		if (v->ar[m_pos(car->pos + 2)].val - 1 >=
		0 && v->ar[m_pos(car->pos + 2)].val - 1 < 16)
		{
			res = tr_to_bin(car->reg[v->ar[m_pos(car->pos + 2)].val - 1]);
			return (res);
		}
	}
	else if (is_valid_codage(cod) == 2)
	{
		res = tr_to_bin(read_arg_dir(v, m_pos(car->pos +
				read_arg_idx(v, m_pos(car->pos + 2))) % IDX_MOD));
		return (res);
	}
	else if (is_valid_codage(cod) == 4)
	{
		res = tr_to_bin(read_arg_dir(v, m_pos(car->pos + 2)));
		return (res);
	}
	return (NULL);
}

char	*take_sec_arg(char *cod, t_kar *car, t_vm *v)
{
	char	*res;
	int		sp;

	sp = is_valid_codage(cod);
	if (is_valid_codage(cod + 2) == 1)
	{
		if (v->ar[m_pos(car->pos + 2 + sp)].val - 1 >=
		0 && v->ar[m_pos(car->pos + 2 + sp)].val - 1 < 16)
		{
			res = tr_to_bin(car->reg[v->ar[m_pos(car->pos + 2 + sp)].val - 1]);
			return (res);
		}
	}
	else if (is_valid_codage(cod + 2) == 2)
	{
		res = tr_to_bin(read_arg_dir(v, m_pos(car->pos +
				read_arg_idx(v, m_pos(car->pos + 2 + sp))) % IDX_MOD));
		return (res);
	}
	else if (is_valid_codage(cod + 2) == 4)
	{
		res = tr_to_bin(read_arg_dir(v, m_pos(car->pos + 2 + sp)));
		return (res);
	}
	return (NULL);
}

void	add_two_arg(char *arg, t_kar *car, t_vm *v, int sp)
{
	if (v->ar[m_pos(car->pos + 2 + sp)].val - 1 >= 0 &&
			v->ar[m_pos(car->pos + 2 + sp)].val - 1 < 16)
	{
		car->reg[v->ar[m_pos(car->pos + 2 + sp)].val - 1] = tr_to_ten(arg);
		carry_change(car, car->reg[v->ar[m_pos(car->pos + 2 + sp)].val - 1]);
	}
}
