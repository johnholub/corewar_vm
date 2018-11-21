/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:22:35 by yholub            #+#    #+#             */
/*   Updated: 2018/02/01 13:22:36 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_digit_mod(t_spec *specif, va_list arg)
{
	int		ret;
	char	*str;
	ssize_t	i_arg;

	if (specif->modif->z == 1)
		i_arg = va_arg(arg, size_t);
	else if (specif->modif->j == 1)
		i_arg = va_arg(arg, intmax_t);
	else if (specif->modif->ll == 1)
		i_arg = va_arg(arg, long long int);
	else if (specif->modif->l == 1)
		i_arg = va_arg(arg, long int);
	else if (specif->modif->h == 1)
		i_arg = (short int)va_arg(arg, int);
	else if (specif->modif->hh == 1)
		i_arg = (signed char)va_arg(arg, int);
	else
		i_arg = va_arg(arg, int);
	str = ft_itoa_d(i_arg);
	ret = handle_flags(str, specif);
	return (ret);
}

int		handle_unsignet_mod(t_spec *specif, va_list arg, int i)
{
	int		ret;
	char	*str;
	size_t	i_arg;

	if (specif->modif->z == 1)
		i_arg = va_arg(arg, size_t);
	else if (specif->modif->j == 1)
		i_arg = va_arg(arg, uintmax_t);
	else if (specif->modif->ll == 1)
		i_arg = (size_t)va_arg(arg, unsigned long long int);
	else if (specif->modif->l == 1)
		i_arg = va_arg(arg, unsigned long int);
	else if (specif->modif->h == 1)
		i_arg = (unsigned short int)va_arg(arg, int);
	else if (specif->modif->hh == 1)
		i_arg = (unsigned char)va_arg(arg, int);
	else
		i_arg = va_arg(arg, unsigned int);
	str = itoa_base(i_arg, (size_t)i);
	if (specif->conv == 'X')
		str = ft_toupperstr(str);
	ret = handle_flags(str, specif);
	return (ret);
}

int		handle_str_mod(t_spec *specif, va_list arg)
{
	int		ret;
	char	*str;

	ret = 0;
	if (specif->conv == 's' && specif->modif->l == 0)
	{
		str = makestr(va_arg(arg, char*));
		ret = handle_flags(str, specif);
	}
	if (specif->conv == 'c' && specif->modif->l == 0)
		ret = handle_char(va_arg(arg, int), specif);
	if (specif->conv == 'C' || (specif->conv == 'c'
			&& specif->modif->l == 1))
		ret = handle_whar(va_arg(arg, wchar_t), specif);
	if ((specif->conv == 'S' || (specif->conv == 's'
			&& specif->modif->l == 1)))
		ret = handle_wstr(va_arg(arg, wchar_t*), specif);
	return (ret);
}

int		handle_none(t_spec *specif)
{
	int		ret;

	if (specif->conv == '\0')
		return (0);
	ret = handle_char(specif->conv, specif);
	return (ret);
}

int		handle_arg(t_spec *specif, va_list arg)
{
	int		ret;

	if (check_conv("Ddi", specif->conv))
		ret = handle_digit_mod(specif, arg);
	else if (check_conv("Xx", specif->conv))
		ret = handle_unsignet_mod(specif, arg, 16);
	else if (check_conv("Uu", specif->conv))
		ret = handle_unsignet_mod(specif, arg, 10);
	else if (check_conv("Oo", specif->conv))
		ret = handle_unsignet_mod(specif, arg, 8);
	else if (check_conv("SsCc", specif->conv))
		ret = handle_str_mod(specif, arg);
	else if (check_conv("p", specif->conv))
		ret = handle_ptr(specif, arg);
	else
		ret = handle_none(specif);
	return (ret);
}
