/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:57:06 by yholub            #+#    #+#             */
/*   Updated: 2018/02/14 17:57:07 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**mass_mask(int i)
{
	char	**res;

	res = (char **)malloc(sizeof(*res) * (size_t)i + 1);
	if (i == 2)
	{
		res[0] = ft_strdup("11000000");
		res[1] = ft_strdup("10000000");
	}
	else if (i == 3)
	{
		res[0] = ft_strdup("11100000");
		res[1] = ft_strdup("10000000");
		res[2] = ft_strdup("10000000");
	}
	else if (i == 4)
	{
		res[0] = ft_strdup("11110000");
		res[1] = ft_strdup("10000000");
		res[2] = ft_strdup("10000000");
		res[3] = ft_strdup("10000000");
	}
	return (res);
}

char	*write_mask(char *val, int i, int len)
{
	char	**mass;
	char	*res;
	int		l;
	int		j;
	int		k;

	l = i;
	mass = mass_mask(i);
	j = len;
	j--;
	while (--i >= 0)
	{
		k = 7;
		while (k > 0 && j >= 0)
		{
			mass[i][k--] = val[j--];
			if (mass[i][k - 1] == '1')
				break ;
		}
	}
	res = copy_and_free(mass, l);
	return (res);
}

char	*print_unicode(wchar_t val)
{
	char	*vstr;
	char	*oct;
	int		len;

	oct = 0;
	vstr = itoa_base((uintmax_t)val, 2);
	len = (int)ft_strlen(vstr);
	if (val <= 2048)
		oct = write_mask(vstr, 2, len);
	else if (val <= 65536)
		oct = write_mask(vstr, 3, len);
	else if (val <= 2097152)
		oct = write_mask(vstr, 4, len);
	free(vstr);
	return (oct);
}

int		handle_ustr(wchar_t c, t_spec *specif)
{
	char		*s;

	s = print_unicode(c);
	if (specif->flag->left_edge && specif->width > 0)
	{
		ft_putstr(s);
		ft_putwidth(specif->width - (int)ft_strlen(s), ' ');
	}
	else if (specif->flag->zero && specif->width > 0)
	{
		ft_putwidth(specif->width - (int)ft_strlen(s), '0');
		ft_putstr(s);
	}
	else if (specif->width > 0)
	{
		ft_putwidth(specif->width - (int)ft_strlen(s), ' ');
		ft_putstr(s);
	}
	else
	{
		put_and_free(s);
		return ((int)ft_strlen(s));
	}
	free(s);
	return (specif->width);
}

int		handle_whar(wchar_t c, t_spec *specif)
{
	int		ret;

	if (c < 128 || MB_CUR_MAX <= 1)
		ret = print_wchar((char)c, specif);
	else
		ret = handle_ustr(c, specif);
	return (ret);
}
