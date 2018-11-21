/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:44:19 by yholub            #+#    #+#             */
/*   Updated: 2018/01/23 13:44:23 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	*new_struct(void)
{
	t_spec *ret;

	ret = (t_spec *)malloc(sizeof(t_spec));
	ret->modif = (t_modif *)malloc(sizeof(t_modif));
	ret->flag = (t_flag *)malloc(sizeof(t_flag));
	ret->modif->h = 0;
	ret->modif->hh = 0;
	ret->modif->l = 0;
	ret->modif->ll = 0;
	ret->modif->j = 0;
	ret->modif->z = 0;
	ret->flag->left_edge = 0;
	ret->flag->alt = 0;
	ret->flag->sign = 0;
	ret->flag->space = 0;
	ret->flag->zero = 0;
	ret->width = 0;
	ret->precision = -1;
	ret->conv = '\0';
	return (ret);
}

int		check_conv(char *comp, char c)
{
	int i;

	i = 0;
	while (comp[i])
	{
		if (comp[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_countwords(char const *s, char c)
{
	if (c == '\0')
		return ((*s == '\0') ? 0 : 1);
	while (*s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s != c && *s != '\0')
		s++;
	return (1 + ft_countwords(s, c));
}

char	*ft_toupperstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - (char)32;
	return (str);
}
