/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:21:07 by yholub            #+#    #+#             */
/*   Updated: 2018/02/19 15:21:07 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_of_str(wchar_t *wstr)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (wstr[i])
	{
		if (wstr[i] < 128)
			len = len + 1;
		else if (wstr[i] < 2048)
			len = len + 2;
		else if (wstr[i] < 65536)
			len = len + 3;
		else if (wstr[i] < 2097152)
			len = len + 4;
		i++;
	}
	return (len);
}

char	*handle_stru(wchar_t *wstr)
{
	char	*str;
	char	*add;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_strnew((size_t)len_of_str(wstr));
	if (wstr == NULL)
		return ("(null)");
	while (wstr[i])
	{
		if (wstr[i] < 128)
			str[j++] = (char)wstr[i];
		else
		{
			add = print_unicode(wstr[i]);
			j = j + (int)ft_strlen(add);
			str = ft_strcat(str, add);
			free(add);
		}
		i++;
	}
	return (str);
}

char	*handle_width_wstr(char *s, t_spec *specif)
{
	char	*res;
	char	*add;

	add = add_width(s, specif);
	if (specif->flag->left_edge)
		res = ft_strjoin(s, add);
	else
		res = ft_strjoin(add, s);
	return (res);
}

char	*handle_wstr_presc(char *s, wchar_t *wstr, t_spec *specif)
{
	int		len;
	int		i;
	char	*res;

	len = len_pesc(wstr, specif);
	res = ft_strnew((size_t)len);
	i = 0;
	while (len > i)
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	return (res);
}

int		handle_wstr(wchar_t *wstr, t_spec *specif)
{
	char		*s;
	int			ret;

	if (wstr)
		s = handle_stru(wstr);
	else
		s = makestr((char *)wstr);
	if (specif->precision >= 0)
		s = handle_wstr_presc(s, wstr, specif);
	if (specif->width > (int)ft_strlen(s))
		s = handle_width_wstr(s, specif);
	ret = (int)ft_strlen(s);
	write(1, s, (size_t)ret);
	free(s);
	return (ret);
}
