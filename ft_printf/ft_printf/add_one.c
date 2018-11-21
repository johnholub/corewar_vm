/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:41:23 by yholub            #+#    #+#             */
/*   Updated: 2018/02/22 17:41:24 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_val(char *format)
{
	if (format[0] == '%' && format[1] == '\0')
		return (1);
	return (0);
}

char	*copy_and_free(char **mass, int l)
{
	char	*res;
	int		j;
	int		k;
	int		g;

	j = 0;
	k = 0;
	g = 0;
	res = (char *)malloc(sizeof(char));
	while (j < l)
		res[j++] = bin_to_dec(mass[k++]);
	res[j] = '\0';
	while (g < l)
		free(mass[g++]);
	free(mass);
	return (res);
}

char	*makestr(char *str)
{
	char	*res;

	if (str == NULL)
		str = "(null)";
	res = ft_strnew(ft_strlen(str));
	res = ft_strcpy(res, str);
	return (res);
}

int		check_len(t_spec *specif, char *str)
{
	int res;

	if (check_conv("Xx", specif->conv) && specif->flag->alt)
		res = specif->precision - ((int)ft_strlen(str) - 2);
	else
		res = specif->precision - (int)ft_strlen(str);
	return (res);
}
