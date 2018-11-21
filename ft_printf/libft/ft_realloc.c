/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:08:12 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 15:56:22 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = ft_strnew(size)))
		return (NULL);
	if (str)
	{
		ft_strcpy(nstr, str);
		ft_strdel(&str);
	}
	return (nstr);
}
