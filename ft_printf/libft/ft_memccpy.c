/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:50:14 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 15:49:57 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		cc;

	i = 0;
	cc = (unsigned char)c;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		if (((unsigned char *)dst)[i - 1] == cc)
		{
			return (&((unsigned char *)dst)[i]);
		}
	}
	return (NULL);
}
