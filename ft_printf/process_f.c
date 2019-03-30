/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:42:24 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:33:35 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_buff(char *str_p, t_ftprintf *f)
{
	char	*str_d;
	int		i;
	int		j;

	i = -1;
	j = ft_intlen(f->ch.val);
	f->ch.len_arg = ft_intlen(f->ch.val) + f->ch.precision;
	while (!f->ch.f_minus
		&& --f->ch.width - ((f->ch.val < 0) ? 1 : 0) > f->ch.len_arg)
		f->ch.f_zero ? free_buff(f, '0') : free_buff(f, ' ');
	(f->ch.n_v) ? free_buff(f, '-') : 0;
	str_d = ft_itoa(ABS(f->ch.val));
	(f->ch.f_space && (!f->ch.f_plus)
		&& f->ch.val > 0) ? free_buff(f, ' ') : 0;
	(f->ch.f_plus && (f->ch.val > 0)) ? free_buff(f, '+') : 0;
	while (++i < j)
		free_buff(f, str_d[i]);
	((f->ch.precision > 0) || f->ch.f_hash) ? free_buff(f, '.') : 0;
	while (*str_p && f->ch.precision--)
		free_buff(f, *str_p++);
	while (f->ch.precision-- > 0)
		free_buff(f, '0');
	while (f->ch.f_minus && (--f->ch.width)
		- ((f->ch.val < 0) ? 1 : 0) > f->ch.len_arg)
		free_buff(f, ' ');
}

void		rounding(t_ftprintf *f)
{
	int		i;
	char	*str_p;

	i = -1;
	str_p = (char *)malloc(sizeof(char) * f->ch.precision);
	while ((++i < f->ch.precision && (str_p[i] = (f->ch.dec_p * 10) + '0')))
		f->ch.dec_p = (f->ch.dec_p * 10) - (str_p[i] - '0');
	if ((f->ch.dec_p * 10) > 5 || ((f->ch.dec_p * 10 == 5)
		&& (f->ch.val % 2 != 0)))
	{
		if (f->ch.true_p && f->ch.precision == 0)
			f->ch.val += 1;
		while ((str_p[--i] == '9') && ((str_p[i] = '0')))
			if (i == 0 && str_p[i] == '0')
				f->ch.val += 1;
		str_p[i] += 1;
	}
	add_buff(str_p, f);
	ft_strdel(&str_p);
}

void		process_f(va_list ap, t_ftprintf *f)
{
	char			*str_p;
	long double		ap_arg;

	ap_arg = f->ch.m_d ? va_arg(ap, long double) : va_arg(ap, double);
	ap_arg == -0.0 ? free_buff(f, '-') : 0;
	if (ap_arg != ap_arg && (str_p = "nan"))
		while (*str_p)
			free_buff(f, *str_p++);
	else if (ap_arg * 2 == ap_arg && ap_arg != 0)
	{
		str_p = ap_arg < 0 ? "-inf" : "inf";
		while (*str_p)
			free_buff(f, *str_p++);
	}
	else
	{
		ap_arg < 0 ? f->ch.n_v = 1 : 0;
		f->ch.val = ap_arg;
		f->ch.dec = 0;
		f->ch.dec_p = ABS(ap_arg - f->ch.val);
		f->ch.precision = !f->ch.true_p ? 6 : f->ch.precision;
		f->ch.pre_s = f->ch.precision;
		rounding(f);
		ft_bzero(&(f->ch), sizeof(t_check));
	}
}
