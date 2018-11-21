/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:27:33 by yholub            #+#    #+#             */
/*   Updated: 2018/08/29 11:27:33 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

int				read_arg_dir(t_vm *v, int i)
{
	unsigned char	buff[4];

	buff[0] = v->ar[m_pos(i + 3)].val;
	buff[1] = v->ar[m_pos(i + 2)].val;
	buff[2] = v->ar[m_pos(i + 1)].val;
	buff[3] = v->ar[m_pos(i)].val;
	return (*(int *)&buff[0]);
}

short			read_arg_idx(t_vm *v, int i)
{
	unsigned char	buff[2];

	buff[0] = v->ar[m_pos(i + 1)].val;
	buff[1] = v->ar[m_pos(i)].val;
	return (*(short *)&buff[0]);
}
