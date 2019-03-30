/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_diuoxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:30:07 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 19:51:51 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_base(const char *format, t_ftprintf *f, int i, va_list *ap)
{
	f->ch.jter = -1;
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		f->ch.base = 10;
	if (format[i] == 'o')
		f->ch.base = 8;
	if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
		f->ch.base = 16;
	format[i] == 'b' ? f->ch.base = 2 : 0;
	format[i] == 'x' ? f->ch.lower = 1 : 0;
	f->ch.conv = format[i];
	if (f->ch.conv == 'd' || f->ch.conv == 'i')
		process_diuoxxp(cast_specifics_s(*ap, f), f);
	else if (f->ch.conv == 'o' || f->ch.conv == 'u'
		|| f->ch.conv == 'p' || ft_tolower(f->ch.conv) == 'x')
		process_diuoxxp(cast_specifics_us(*ap, f), f);
}

void		settings(size_t ap_arg, t_ftprintf *f)
{
	f->ch.n_v && f->ch.width--;
	f->ch.f_space && !f->ch.f_plus && !f->ch.n_v && f->ch.width--;
	f->ch.f_plus && !f->ch.n_v && f->ch.base == 10 && f->ch.width--;
	f->ch.f_hash && ap_arg && f->ch.base == 8 && f->ch.width--;
	((f->ch.f_hash && f->ch.base == 16) || (f->ch.base == 16)) && (ap_arg || f->ch.conv == 'p')
		&& (f->ch.width -= 2);
	if (!(!f->ch.pre_s && f->ch.f_zero) && !f->ch.f_minus)
		while (f->ch.width-- > 0)
			free_buff(f, f->ch.space_zero);
	f->ch.f_space && (f->ch.conv == 'd' || f->ch.conv == 'i')
		&& !f->ch.f_plus && !f->ch.n_v ? free_buff(f, ' ') : 0;
	f->ch.n_v ? free_buff(f, '-') : 0;
	f->ch.f_plus && !f->ch.n_v && (f->ch.conv == 'd' || f->ch.conv == 'i') ?
		free_buff(f, '+') : 0;
	f->ch.f_hash && f->ch.base == 8 ? free_buff(f, '0') : 0;
	if ((f->ch.f_hash && f->ch.base == 16 && ap_arg)
		|| (f->ch.conv == 'p' && f->ch.base == 16))
	{
		free_buff(f, '0');
		free_buff(f, f->ch.conv == 'X' ? 'X' : 'x');
	}
	if (!f->ch.pre_s && f->ch.f_zero && !f->ch.f_minus)
		while (f->ch.width-- > 0)
			free_buff(f, f->ch.space_zero);
}

void		process_diuoxxp(size_t ap_arg, t_ftprintf *f)
{
	bool	i;

	f->ch.tmp = ft_itoa_base(ap_arg, f->ch.base);
	f->ch.len_arg = ft_strlen(f->ch.tmp);
	if (f->ch.lower == 1)
		while (f->ch.iter < f->ch.len_arg)
			f->ch.tmp[f->ch.iter] > 64 && f->ch.tmp[f->ch.iter] < 91 ?
			f->ch.tmp[f->ch.iter++] += 32 : f->ch.tmp[f->ch.iter++];
	!f->ch.precision && f->ch.true_p && f->ch.width++;
	f->ch.precision -= f->ch.len_arg + (f->ch.f_hash
		&& ap_arg && f->ch.base == 8);
	f->ch.width -= (f->ch.precision > 0 ? f->ch.precision : 0) + f->ch.len_arg;
	f->ch.space_zero = (f->ch.f_zero && !f->ch.true_p) ? '0' : ' ';
	settings(ap_arg, f);
	i = !(ap_arg == 0 && ((f->ch.true_p && f->ch.precision < 0)
		|| (f->ch.base == 8 && f->ch.f_hash)));
	while (f->ch.precision-- > 0)
		free_buff(f, '0');
	if (i)
		while (++f->ch.jter < f->ch.len_arg)
			f->ch.conv == 'p' ? free_buff(f, ft_tolower(f->ch.tmp[f->ch.jter]))
				: free_buff(f, f->ch.tmp[f->ch.jter]);
	free(f->ch.tmp);
	while (f->ch.width-- > 0)
		free_buff(f, ' ');
}
