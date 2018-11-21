/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:29:14 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 14:29:15 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	check_fd(int fd)
{
	if (fd <= 0)
	{
		ft_putendl_fd("Not valid file", 2);
		exit(1);
	}
}

int		vm_set_dump(t_flags *fl, char **str, int i)
{
	if (!str[i + 1])
	{
		ft_putendl_fd("Wrong number of cycles", 2);
		exit(1);
	}
	fl->dump = 1;
	fl->cycle = ft_atoi(str[i + 1]);
	return (1);
}

int		get_player_number(t_vm *v, int pos, char *num, char *file)
{
	if (!num || !file)
	{
		ft_putendl_fd("Wrong input information", 2);
		exit(1);
	}
	if (ft_atoi(num) != 0 || (ft_atoi(num) == 0 &&
			ft_strlen(num) == 1 && num[0] == '0'))
	{
		if (is_cor_format(file) == 0)
		{
			ft_putendl_fd("Wrong file format", 2);
			exit(1);
		}
		if (ft_atoi(num) != 0 && num_size(ft_atoi(num)) == (int)ft_strlen(num))
		{
			v->p[pos].p_n = ft_atoi(num);
			v->p[pos].fd = open(file, O_RDONLY);
			check_fd(v->p[pos].fd);
			v->cou_pl++;
			return (2);
		}
	}
	ft_putendl_fd("Wrong input information", 2);
	exit(1);
}

int		vm_get_player(char *file, int pos, t_vm *v)
{
	v->p[pos].p_n = (pos + 1) * -1;
	v->p[pos].fd = open(file, O_RDONLY);
	check_fd(v->p[pos].fd);
	return (1);
}

int		parse_flags(t_vm *v, t_flags *fl, char **str, int i)
{
	int res;

	res = 0;
	if (!ft_strcmp(str[i], "-dump"))
		res += vm_set_dump(fl, str, i);
	else if (!ft_strcmp(str[i], "-v"))
		fl->v = 1;
	else if (!ft_strcmp(str[i], "-a"))
		fl->a = 1;
	else if (!ft_strcmp(str[i], "-l"))
		fl->l = 1;
	else if (!ft_strcmp(str[i], "-n"))
		res += get_player_number(v, v->cou_pl, str[i + 1], str[i + 2]);
	else if (is_cor_format(str[i]))
		v->cou_pl += vm_get_player(str[i], v->cou_pl, v);
	else
	{
		ft_putendl_fd("Wrong input format", 2);
		exit(1);
	}
	return (res);
}
