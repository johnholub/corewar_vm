/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:47:39 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 15:46:35 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	k;

	len = ft_size(n);
	k = n;
	if (k == 0)
		return (ft_strsub("0", 0, 1));
	if (n < 0)
	{
		k = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = k % 10 + '0';
	while (k /= 10)
		str[--len] = k % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
