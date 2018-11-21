/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator_symbols.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:24:43 by yholub            #+#    #+#             */
/*   Updated: 2018/01/11 14:24:44 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_modif(const char *onefor, t_spec *specif)
{
	int j;

	j = 0;
	if (onefor[0] == 'h' && onefor[1] != 'h')
		return (specif->modif->h = 1);
	else if (onefor[0] == 'h' && onefor[1] == 'h')
	{
		specif->modif->hh = 1;
		j += 2;
	}
	else if (onefor[0] == 'l' && onefor[1] != 'l')
		return (specif->modif->l = 1);
	else if (onefor[0] == 'l' && onefor[1] == 'l')
	{
		specif->modif->ll = 1;
		j += 2;
	}
	else if (*onefor == 'j')
		return (specif->modif->j = 1);
	else if (*onefor == 'z')
		return (specif->modif->z = 1);
	return (j);
}

int		check_flag(const char *onefor, t_spec *specif)
{
	if (*onefor == '#')
		return (specif->flag->alt = 1);
	else if (*onefor == ' ')
		return (specif->flag->space = 1);
	else if (*onefor == '+')
		return (specif->flag->sign = 1);
	else if (*onefor == '-')
		return (specif->flag->left_edge = 1);
	else if (*onefor == '0' && !ft_isdigit(*onefor - 1) &&
		*onefor - 1 != '.')
		return (specif->flag->zero = 1);
	return (0);
}

int		check_width(const char *onefor, t_spec *specif, va_list arg)
{
	int j;

	j = 0;
	if (*onefor == '*')
	{
		specif->width = va_arg(arg, int);
		if (specif->width < 0)
		{
			specif->width = -specif->width;
			specif->flag->left_edge = 1;
		}
		return (1);
	}
	if (ft_isdigit(*onefor) && *onefor > '0')
	{
		specif->width = ft_atoi(onefor);
		while (ft_isdigit(*onefor))
		{
			onefor++;
			j++;
		}
	}
	return (j);
}

int		check_precision(const char *onefor, t_spec *specif, va_list arg)
{
	int		j;

	j = 0;
	if (*onefor == '.')
	{
		onefor++;
		if (!ft_isdigit(*onefor) && *onefor != '*')
			specif->precision = 0;
		if (*onefor == '*')
		{
			specif->precision = va_arg(arg, int);
			if (specif->precision < 0)
				specif->precision = -1;
			return (2);
		}
		if (ft_isdigit(*onefor))
			specif->precision = ft_atoi(onefor);
		while (ft_isdigit(*onefor))
		{
			onefor++;
			j++;
		}
		j++;
	}
	return (j);
}

int		accept_spec(const char *format, va_list arg, t_spec *specif)
{
	if (format + 1 == '\0')
		return (*format);
	format++;
	while (format && !specif->conv)
	{
		if (check_flag(format, specif))
			format += check_flag(format, specif);
		else if (ft_isdigit(*format) ||
				(*format == '*' && *format - 1 != '.'))
			format += check_width(format, specif, arg);
		else if (*format == '.')
			format += check_precision(format, specif, arg);
		else if (check_modif(format, specif))
			format += check_modif(format, specif);
		else
			specif->conv = *format;
	}
	if (check_conv("DOUSC", specif->conv))
		specif->modif->l = 1;
	return (specif->conv);
}
