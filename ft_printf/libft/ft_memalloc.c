/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:34:00 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 15:49:24 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*addr;
	size_t	i;

	addr = malloc(size);
	if (addr == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)addr)[i] = 0;
	return (addr);
}
