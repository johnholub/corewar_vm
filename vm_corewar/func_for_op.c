/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:43:10 by yholub            #+#    #+#             */
/*   Updated: 2018/09/04 16:43:10 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

char			*ft_xor_arr(char *f_arg, char *s_arg)
{
	char	*res;
	int		i;

	i = 31;
	res = ft_strnew(32);
	while (i >= 0)
	{
		if (s_arg[i] != f_arg[i])
			res[i] = '1';
		else
			res[i] = '0';
		i--;
	}
	return (res);
}

char			*ft_or_arr(char *f_arg, char *s_arg)
{
	char	*res;
	int		i;

	i = 31;
	res = ft_strnew(32);
	while (i >= 0)
	{
		if (s_arg[i] == '1' || f_arg[i] == '1')
			res[i] = '1';
		else
			res[i] = '0';
		i--;
	}
	return (res);
}

char			*ft_add_arr(char *f_arg, char *s_arg)
{
	char	*res;
	int		i;

	i = 31;
	res = ft_strnew(32);
	while (i >= 0)
	{
		if (s_arg[i] == '1' && f_arg[i] == '1')
			res[i] = '1';
		else
			res[i] = '0';
		i--;
	}
	return (res);
}

unsigned int	tr_to_ten(char *s)
{
	int				i;
	unsigned int	add;
	unsigned int	res;

	i = 31;
	add = 1;
	res = 0;
	while (i >= 0)
	{
		if (s[i] == '1')
			res = res + add;
		add = add * 2;
		i--;
	}
	return (res);
}
