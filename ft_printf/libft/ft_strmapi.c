/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:00:26 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 15:59:07 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*out;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (size + 1));
	if (out == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		out[i] = (*f)(i, s[i]);
	out[i] = '\0';
	return (out);
}
