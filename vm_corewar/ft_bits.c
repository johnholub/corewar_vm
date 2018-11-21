/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:06:54 by yholub            #+#    #+#             */
/*   Updated: 2018/08/28 17:06:54 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

char	*ft_from16to2(unsigned char num)
{
	char	*str;
	int		div;
	int		i;

	div = 128;
	i = -1;
	str = ft_strnew(9);
	while (++i < 8 && div != 0)
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
	str[8] = '\0';
	return (str);
}

t_kar	*ft_operations2(t_vm *v, t_kar *car)
{
	if (car->com == 9)
		car = ft_zjmp(v, car);
	else if (car->com == 10)
		car = ft_ldi(v, car);
	else if (car->com == 11)
		car = ft_sti(v, car);
	else if (car->com == 12)
		car = ft_fork(v, car);
	else if (car->com == 13)
		car = ft_lld(v, car);
	else if (car->com == 14)
		car = ft_lldi(v, car);
	else if (car->com == 15)
		car = ft_lfork(v, car);
	else if (car->com == 16)
		car = ft_aff(v, car);
	else
		car->pos++;
	return (car);
}

t_kar	*ft_operations(t_vm *v, t_kar *car)
{
	if (car->com == 1)
		car = ft_live(v, car);
	else if (car->com == 2)
		car = ft_ld(v, car);
	else if (car->com == 3)
		car = ft_st(v, car);
	else if (car->com == 4)
		car = ft_add(v, car);
	else if (car->com == 5)
		car = ft_sub(v, car);
	else if (car->com == 6)
		car = ft_and(v, car);
	else if (car->com == 7)
		car = ft_or(v, car);
	else if (car->com == 8)
		car = ft_xor(v, car);
	else
		car = ft_operations2(v, car);
	return (car);
}
