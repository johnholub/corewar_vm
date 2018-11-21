/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:37:38 by yholub            #+#    #+#             */
/*   Updated: 2018/02/05 12:37:39 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_ptr(t_spec *specif, va_list arg)
{
	int		ret;
	char	*s;
	char	*str;
	size_t	i;

	i = (size_t)va_arg(arg, void*);
	if (i == 0)
	{
		s = ft_strnew(5);
		str = ft_strnew(5);
		s = ft_strcpy(s, "0x0");
		str = ft_strcpy(str, s);
	}
	else
	{
		s = itoa_base(i, 16);
		str = ft_strjoin("0x", s);
	}
	ret = handle_flags(str, specif);
	free(s);
	return (ret);
}

int			handle_char(int c, t_spec *specif)
{
	if (specif->flag->left_edge && specif->width > 0)
	{
		ft_putchar((char)c);
		ft_putwidth(specif->width - 1, ' ');
	}
	else if (specif->flag->zero && specif->width > 0)
	{
		ft_putwidth(specif->width - 1, '0');
		ft_putchar((char)c);
	}
	else if (specif->width > 0)
	{
		ft_putwidth(specif->width - 1, ' ');
		ft_putchar((char)c);
	}
	else
	{
		ft_putchar((char)c);
		return (1);
	}
	return (specif->width);
}

int			print_wchar(char c, t_spec *specif)
{
	if (specif->flag->left_edge && specif->width > 0)
	{
		write(1, &c, 1);
		ft_putwidth(specif->width - 1, ' ');
	}
	else if (specif->flag->zero && specif->width > 0)
	{
		ft_putwidth(specif->width - 1, '0');
		write(1, &c, 1);
	}
	else if (specif->width > 0)
	{
		ft_putwidth(specif->width - 1, ' ');
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		return (1);
	}
	return (specif->width);
}

void		free_struct(t_spec *specif)
{
	free(specif->flag);
	free(specif->modif);
	free(specif);
}

void		put_and_free(char *s)
{
	ft_putstr(s);
	free(s);
}
