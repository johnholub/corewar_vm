/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:00:21 by yholub            #+#    #+#             */
/*   Updated: 2018/02/01 15:00:22 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_hash(char *str, char c)
{
	char	*newstr;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = (int)ft_strlen(str) + 2;
	newstr = ft_strnew((size_t)len);
	if (check_conv("xX", c) && ft_strcmp(str, "0") != 0)
	{
		newstr[i++] = '0';
		newstr[i++] = c;
		while (len > i)
			newstr[i++] = str[j++];
	}
	else if (check_conv("Oo", c) && ft_strcmp(str, "0") != 0)
	{
		newstr[0] = '0';
		newstr = ft_strcat(newstr, str);
	}
	else
		return (str);
	free(str);
	return (newstr);
}

char	*flag_plus(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = ft_strnew(ft_strlen(str) + 1);
	if (ft_atoi_x(str) >= 0)
	{
		if (specif->flag->sign == 1)
			newstr[i++] = '+';
		else if (specif->flag->space == 1)
			newstr[i++] = ' ';
	}
	while (str[j])
		newstr[i++] = str[j++];
	free(str);
	return (newstr);
}

int		handle_flags(char *str, t_spec *specif)
{
	int		ret;

	if (specif->flag->alt == 1 && check_conv("XxOo", specif->conv))
		str = flag_hash(str, specif->conv);
	if ((specif->flag->sign == 1 || specif->flag->space == 1)
			&& check_conv("Ddi", specif->conv))
		str = flag_plus(str, specif);
	if (check_conv("DdiXxOoUuSsp", specif->conv))
		str = handle_precision(str, specif);
	if (specif->width > (int)ft_strlen(str) &&
			check_conv("sSpdDioOuUxXcC", specif->conv))
		str = handle_width(str, specif);
	ret = (int)ft_strlen(str);
	str[ft_strlen(str)] = '\0';
	ft_putstr(str);
	free(str);
	return (ret);
}
