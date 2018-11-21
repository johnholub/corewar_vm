/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:51:26 by yholub            #+#    #+#             */
/*   Updated: 2018/01/05 14:51:27 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_end_ret(char c, int i)
{
	ft_putchar(c);
	i++;
	return (i);
}

char	*ignore_to(int size, char *format)
{
	if (format + 1 == '\0')
		return (format + 1);
	while (format && *format != size)
		format++;
	return (format);
}

char	*handle_two(char *format, int ret)
{
	int		not_first;

	not_first = 0;
	while ((*format != '%' || not_first == 0) && *format)
	{
		ft_putchar(*format++);
		not_first++;
		ret++;
	}
	return (format);
}

int		printfunc(char *format, va_list arg)
{
	int		size;
	int		ret;
	t_spec	*specs;

	ret = 0;
	while (ft_strlen(format) > 0 && !check_for_val(format))
	{
		if (*format == '%' && *format + 1 == '%')
		{
			format = handle_two(format, ret);
			ret++;
		}
		else if (*format == '%')
		{
			specs = new_struct();
			size = accept_spec(format, arg, specs);
			ret += handle_arg(specs, arg);
			format = ignore_to(size, format + 1);
			free_struct(specs);
		}
		else
			ret = ft_put_end_ret(*format, ret);
		format++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = printfunc((char*)format, arg);
	va_end(arg);
	return (ret);
}
