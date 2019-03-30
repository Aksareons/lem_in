/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:08:06 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:52:13 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 4096

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <inttypes.h>
# include "libft/libft.h"

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

typedef struct	s_check
{
	char		conv;
	char		space_zero;
	int			f_minus;
	int			f_plus;
	int			f_space;
	int			f_hash;
	int			f_zero;
	int			n_v;
	int			m_h;
	int			m_hh;
	int			m_l;
	int			m_ll;
	int			m_d;
	int			true_p;
	int			t_width;
	int			place;
	int			len_arg;
	int			base;
	int			lower;
	int			precision;
	int			width;
	int			pre_s;
	int			iter;
	int			jter;
	intmax_t	dec;
	intmax_t	val;
	long double	dec_p;
	char		*tmp;
}				t_check;

typedef struct	s_ftprintf
{
	char		buff[BUFF_SIZE];
	int			count;
	size_t		i;
	t_check		ch;

}				t_ftprintf;

int				ft_printf(const char *format, ...);
int				parse(const char *format, t_ftprintf *f, va_list *ap, int i);
int				check_parse_f(const char *format, t_ftprintf *f, int i);
int				check_parse_wp(const char *format, t_ftprintf *f, int i);
int				check_parse_l(const char *format, t_ftprintf *f, int i);
int				check_parse_h(const char *format, t_ftprintf *f, int i);
int				print_value_type(const char *format, t_ftprintf *f,
				va_list *ap, int i);
intmax_t		cast_specifics_s(va_list ap, t_ftprintf *f);
uintmax_t		cast_specifics_us(va_list ap, t_ftprintf *f);
void			free_buff(t_ftprintf *f, char c);
intmax_t		m_p_s(t_ftprintf *f, intmax_t ap_arg);
intmax_t		align_prec(t_ftprintf *f, intmax_t ap_arg);
intmax_t		new_precision(t_ftprintf *f, intmax_t ap_arg);
intmax_t		check_w_p(t_ftprintf *f, intmax_t ap_arg);
void			process_c(t_ftprintf *f, va_list ap);
void			process_pr(t_ftprintf *f);
void			process_s(t_ftprintf *f, va_list ap);
void			check_base(const char *format, t_ftprintf *f, int i,
				va_list *ap);
void			process_diuoxxp(size_t ap_arg, t_ftprintf *f);
void			check_base(const char *format, t_ftprintf *f,
				int i, va_list *ap);
void			settings(size_t ap_arg, t_ftprintf *f);
void			process_f(va_list ap, t_ftprintf *f);
void			add_buff(char *str_p, t_ftprintf *f);
void			rounding(t_ftprintf *f);
#endif
