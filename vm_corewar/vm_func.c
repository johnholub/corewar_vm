/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:49:29 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 15:49:29 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

void	exit_prog_err(void)
{
	ft_putendl_fd("Wrong number of players", 2);
	exit(0);
}

int		num_size(int src)
{
	int res;

	res = 1;
	if (src < 0)
		res++;
	while (src / 10)
	{
		res++;
		src = src / 10;
	}
	return (res);
}

int		is_cor_format(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strlen(str) > 3)
	{
		while (*str)
			str++;
		if (!ft_strcmp(str - 4, ".cor"))
			return (1);
	}
	return (0);
}

int		count_corf(char **argv, int argc)
{
	int		res;
	int		i;

	res = 0;
	i = 1;
	while (i < argc)
	{
		if (is_cor_format(argv[i]))
			res++;
		i++;
	}
	return (res);
}
