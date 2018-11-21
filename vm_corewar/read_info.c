/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:22:40 by yholub            #+#    #+#             */
/*   Updated: 2018/08/21 15:22:41 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_cw.h"

unsigned int	magic_head(unsigned int *str)
{
	char			*temp;
	char			*res;
	char			*buff;
	unsigned int	head;
	int				i;

	i = 1;
	res = itoa_base(str[0], 16);
	while (i < 4)
	{
		temp = ft_strdup(res);
		ft_strdel(&res);
		buff = itoa_base(str[i], 16);
		res = ft_strjoin(temp, buff);
		ft_strdel(&buff);
		ft_strdel(&temp);
		i++;
	}
	head = (unsigned int)ft_atoi_base(res, 16);
	ft_strdel(&res);
	return (head);
}

void			get_size_of_bot(t_player pl)
{
	unsigned char buff[4];

	read(pl.fd, &buff[3], 1);
	read(pl.fd, &buff[2], 1);
	read(pl.fd, &buff[1], 1);
	read(pl.fd, &buff[0], 1);
	pl.head->prog_size = (*(unsigned int *)&buff[0]);
	if (pl.head->prog_size > CHAMP_MAX_SIZE)
	{
		ft_putendl_fd("Not valid size of bot", 2);
		exit(1);
	}
}

void			get_magic_head(t_player pl)
{
	unsigned int *buff;

	buff = (unsigned int *)malloc(sizeof(unsigned int) * 4);
	buff[0] = 0;
	buff[1] = 0;
	buff[2] = 0;
	buff[3] = 0;
	read(pl.fd, &buff[0], 1);
	read(pl.fd, &buff[1], 1);
	read(pl.fd, &buff[2], 1);
	read(pl.fd, &buff[3], 1);
	pl.head->magic = magic_head(buff);
	free(buff);
	if (pl.head->magic != COREWAR_EXEC_MAGIC)
	{
		ft_putendl_fd("Wrong magic header", 2);
		exit(1);
	}
}
