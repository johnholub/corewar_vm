/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:42:38 by yholub            #+#    #+#             */
/*   Updated: 2018/02/14 18:42:39 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwidth(int i, char c)
{
	while (i > 0)
	{
		i--;
		ft_putchar(c);
	}
}

char	bin_to_dec(char *i)
{
	int j;
	int res;

	j = 0;
	res = 0;
	while (8 > j)
	{
		res = res * 2 + (i[j] - 48);
		j++;
	}
	return ((char)res);
}

int		len_plus(wchar_t c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 2097152)
		return (4);
	return (0);
}

int		len_pesc(wchar_t *wstr, t_spec *specif)
{
	int i;
	int j;
	int res;

	i = 0;
	res = 0;
	while (res < specif->precision)
	{
		j = len_plus(wstr[i]);
		if (res + j > specif->precision)
			return (res);
		res += j;
	}
	return (res);
}

char	*add_width(char *s, t_spec *specif)
{
	int		i;
	int		len;
	char	*res;
	char	c;

	i = 0;
	len = specif->width - (int)ft_strlen(s);
	res = ft_strnew((size_t)len);
	if (specif->flag->left_edge)
		c = ' ';
	else if (specif->flag->zero)
		c = '0';
	else
		c = ' ';
	while (len > i)
	{
		res[i] = c;
		i++;
	}
	return (res);
}
