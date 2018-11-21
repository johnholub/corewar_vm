/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:52:54 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 16:02:00 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s)
{
	size_t	start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	return (start);
}

static size_t	ft_len(char const *s, size_t len)
{
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	long	size;
	size_t	i;
	char	*rtn;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	if ((int)len == -1)
		return (ft_strnew(1));
	i = 0;
	start = ft_start(s);
	len = ft_len(s, len);
	size = len - start;
	if ((rtn = (char*)ft_memalloc(sizeof(char) *
	((size * (size > 0) + 1) + 1))))
	{
		while (start < len + 1)
			rtn[i++] = s[start++];
		i++;
		rtn[i] = '\0';
	}
	return (rtn);
}
