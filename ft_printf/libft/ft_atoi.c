/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:57:12 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 15:44:46 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	result;
	int					is_neg;

	i = 0;
	result = 0;
	while (ft_iswhitespace(*str))
		str++;
	is_neg = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		i++;
		if (result >= 9223372036854775807 && is_neg == 0)
			return (-1);
		if (result > 9223372036854775807 && is_neg == 1)
			return (0);
	}
	return (is_neg ? -result : result);
}
