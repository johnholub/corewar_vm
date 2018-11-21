/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_verb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:51:56 by yholub            #+#    #+#             */
/*   Updated: 2018/09/21 11:51:56 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int		get_reg_for_and(t_vm *v, t_kar *car, char *cod)
{
	int res;

	res = v->ar[m_pos(is_valid_codage(cod) +
			is_valid_codage(cod + 2) + car->pos) + 2].val;
	return (res);
}
