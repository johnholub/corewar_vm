/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:03:36 by yholub            #+#    #+#             */
/*   Updated: 2018/02/02 17:03:39 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_minus(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = ft_strnew((size_t)specif->width);
	while (str[i])
		newstr[j++] = str[i++];
	while (j < specif->width)
		newstr[j++] = ' ';
	free(str);
	return (newstr);
}

char	*width_zero(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;
	int		slen;

	i = 0;
	j = 0;
	newstr = ft_strnew((size_t)specif->width);
	if ((specif->flag->alt == 1 && (check_conv("XxOo", specif->conv)))
			|| check_conv("-+", str[i]) || specif->conv == 'p'
			|| specif->flag->space == 1)
	{
		newstr[i++] = str[j++];
		if (check_conv("Xx", specif->conv) || specif->conv == 'p')
			newstr[i++] = str[j++];
	}
	slen = specif->width - (int)ft_strlen(str);
	while (--slen >= 0)
		newstr[j++] = '0';
	newstr = ft_strcat(newstr, str + i);
	free(str);
	return (newstr);
}

char	*width_only(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (specif->width > (int)ft_strlen(str))
		newstr = ft_strnew((size_t)specif->width);
	else
	{
		newstr = str;
		return (newstr);
	}
	while (j < (specif->width - (int)ft_strlen(str)))
		newstr[j++] = ' ';
	while (str[i])
		newstr[j++] = str[i++];
	free(str);
	return (newstr);
}

char	*handle_width(char *str, t_spec *specif)
{
	if (specif->width > (int)ft_strlen(str))
	{
		if (specif->flag->left_edge == 1)
			str = width_minus(str, specif);
		else if ((specif->flag->zero == 1 && specif->precision == -1)
				|| (specif->flag->zero == 1 && check_conv("Ss", specif->conv)))
			str = width_zero(str, specif);
		else
			str = width_only(str, specif);
	}
	return (str);
}
