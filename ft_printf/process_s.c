/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:46:00 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:28:43 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precision_s(t_ftprintf *f)
{
	if (f->ch.precision < f->ch.len_arg)
		f->ch.len_arg = f->ch.precision;
	if (f->ch.precision > f->ch.len_arg)
		f->ch.precision = f->ch.len_arg;
	if (f->ch.width < f->ch.precision)
		f->ch.width = 0;
}

void		process_s(t_ftprintf *f, va_list ap)
{
	char	*str;
	int		leng;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	f->ch.len_arg = ft_strlen(str);
	if (f->ch.true_p)
		precision_s(f);
	leng = f->ch.len_arg;
	f->ch.space_zero = f->ch.f_zero ? '0' : ' ';
	if (!f->ch.f_minus)
		while (f->ch.width && (f->ch.width--) > f->ch.len_arg)
			free_buff(f, f->ch.space_zero);
	if (f->ch.len_arg > 0)
		while (f->ch.len_arg-- && str)
			free_buff(f, *str++);
	if (f->ch.f_minus)
		while (f->ch.width && (f->ch.width--) > leng)
			free_buff(f, f->ch.space_zero);
	ft_bzero(&f->ch, sizeof(f->ch));
}
