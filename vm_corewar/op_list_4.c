/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:12:11 by yholub            #+#    #+#             */
/*   Updated: 2018/08/28 17:12:12 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	st_reg_reg(t_kar *car, unsigned char src, unsigned char dst)
{
	if (src - 1 >= 0 && src - 1 < 16 && dst - 1 >= 0 && dst - 1 < 16)
		car->reg[dst - 1] = car->reg[src - 1];
}

void	carry_change(t_kar *car, int i)
{
	if (i == 0)
		car->carry = 1;
	else
		car->carry = 0;
}

void	change_carry_reg(t_kar *car, unsigned char i, int val)
{
	if (i - 1 >= 0 && i - 1 < 16)
	{
		car->reg[i - 1] = val;
		carry_change(car, car->reg[i - 1]);
	}
}

t_kar	*ft_aff(t_vm *v, t_kar *car)
{
	char	*cod;

	cod = ft_from16to2(v->ar[m_pos(car->pos + 1)].val);
	if (is_valid_codage(cod) == 1)
	{
		if (v->fl->a == 1)
			ft_printf("Aff: %c\n",
					car->reg[v->ar[m_pos(car->pos + 2)].val - 1] % 256);
		car->pos = m_pos(car->pos + 3);
	}
	else
		car->pos = m_pos(car->pos + 2 + is_valid_codage(cod));
	free(cod);
	return (car);
}

int		is_ex_pl_numb(t_vm *v, int num)
{
	int i;

	i = 0;
	while (i < v->cou_pl)
	{
		if (v->p[i].p_n == num)
			return (1);
		i++;
	}
	return (0);
}
