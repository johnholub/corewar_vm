/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:13:10 by yholub            #+#    #+#             */
/*   Updated: 2018/02/02 14:13:11 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_alt(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = check_len(specif, str);
	if (((int)ft_strlen(str) - 2) < specif->precision)
		newstr = ft_strnew((size_t)specif->precision
		+ (size_t)len);
	else
		return (str);
	if (specif->flag->alt == 1 && !(check_conv("Uu", specif->conv)))
	{
		newstr[i++] = str[j++];
		if (check_conv("Xx", specif->conv))
			newstr[i++] = str[j++];
	}
	while (--len >= 0)
		newstr[i++] = '0';
	while (j < (int)ft_strlen(str))
		newstr[i++] = str[j++];
	free(str);
	return (newstr);
}

char	*precision_sign(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;
	int		plus;

	i = 0;
	j = 0;
	plus = 0;
	if (specif->precision < (int)ft_strlen(str))
		return (str);
	newstr = ft_strnew((size_t)specif->precision);
	if (((specif->flag->sign == 1 || specif->flag->space == 1)
			|| ft_atoi(str) < 0))
	{
		newstr[i++] = str[j++];
		plus++;
	}
	len = specif->precision + plus - (int)ft_strlen(str);
	while (--len >= 0)
		newstr[i++] = '0';
	while (str[j])
		newstr[i++] = str[j++];
	free(str);
	return (newstr);
}

char	*prec_to_str(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(str);
	if (specif->precision != -1 && specif->precision < len)
	{
		newstr = ft_strnew((size_t)specif->precision);
		len = specif->precision;
	}
	else
		newstr = ft_strnew((size_t)len);
	while (str[i] != '\0' && i < len)
		newstr[j++] = str[i++];
	free(str);
	return (newstr);
}

char	*prec_to_ptr(char *str, t_spec *specif)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (specif->precision == 0 && !ft_strcmp(str, "0x0"))
		newstr = ft_strdup("0x");
	else if (specif->precision > ((int)ft_strlen(str) - 2))
	{
		newstr = ft_strnew((size_t)specif->precision + 2);
		newstr[i++] = str[j++];
		newstr[i++] = str[j++];
		len = specif->precision - ((int)ft_strlen(str) - 2);
		while (--len >= 0)
			newstr[i++] = '0';
		while (str[j])
			newstr[i++] = str[j++];
		newstr[i] = '\0';
	}
	else
		return (str);
	free(str);
	return (newstr);
}

char	*handle_precision(char *str, t_spec *specif)
{
	if (specif->precision >= 0)
	{
		if (specif->precision == 0 && ft_strcmp(str, "0") == 0
				&& (!check_conv("Oo", specif->conv)
				|| (check_conv("Oo", specif->conv)
				&& specif->flag->alt == 0)))
			str = ft_strnew(1);
		else if (check_conv("OoXxUu", specif->conv))
			str = precision_alt(str, specif);
		else if (check_conv("Ddi", specif->conv))
			str = precision_sign(str, specif);
		else if (check_conv("Ss", specif->conv))
			str = prec_to_str(str, specif);
		else if (specif->conv == 'p')
			str = prec_to_ptr(str, specif);
	}
	return (str);
}
