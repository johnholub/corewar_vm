/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:51:43 by yholub            #+#    #+#             */
/*   Updated: 2018/01/05 14:51:44 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "locale.h"
# include "../libft/libft.h"

typedef struct	s_flag
{
	int			left_edge;
	int			sign;
	int			space;
	int			alt;
	int			zero;
}				t_flag;

typedef struct	s_modif
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_modif;

typedef struct	s_spec
{
	t_flag		*flag;
	int			width;
	int			precision;
	t_modif		*modif;
	char		conv;
}				t_spec;

int				ft_printf(const char *format, ...);
t_spec			*new_struct(void);
int				ft_countwords(char const *s, char c);
int				accept_spec(const char *format,
	va_list arg, t_spec *specif);
int				handle_arg(t_spec *specif, va_list arg);
int				check_conv(char *comp, char c);
char			*itoa_base(ssize_t i, size_t base);
char			*ft_itoa_d(ssize_t n);
char			*ft_toupperstr(char *str);
int				handle_flags(char *str, t_spec *specif);
char			*handle_precision(char *str, t_spec *specif);
char			*handle_width(char *str, t_spec *specif);
int				handle_ptr(t_spec *specif, va_list arg);
int				handle_char(int c, t_spec *specif);
ssize_t			ft_atoi_x(const char *str);
void			free_struct(t_spec *specif);
int				handle_whar(wchar_t c, t_spec *specif);
void			ft_putwidth(int i, char c);
int				print_wchar(char c, t_spec *specif);
int				handle_wstr(wchar_t *wstr, t_spec *specif);
char			*print_unicode(wchar_t val);
int				len_pesc(wchar_t *wstr, t_spec *specif);
char			*add_width(char *s, t_spec *specif);
char			bin_to_dec(char *i);
void			put_and_free(char *s);
char			*makestr(char *str);
char			*copy_and_free(char **mass, int l);
int				check_for_val(char *format);
int				check_len(t_spec *specif, char *str);

#endif
