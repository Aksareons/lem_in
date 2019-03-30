/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_specifics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 05:38:20 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/14 18:31:26 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	cast_specifics_s(va_list ap, t_ftprintf *f)
{
	intmax_t ap_arg;

	if (f->ch.m_l)
		ap_arg = va_arg(ap, long int);
	else if (f->ch.m_ll)
		ap_arg = va_arg(ap, long long int);
	else if (f->ch.m_h)
		ap_arg = (short int)va_arg(ap, int);
	else if (f->ch.m_hh)
		ap_arg = (signed char)va_arg(ap, int);
	else
		ap_arg = va_arg(ap, int);
	ap_arg < 0 ? f->ch.n_v = 1 : 0;
	return ((ap_arg < 0) ? -ap_arg : ap_arg);
}

uintmax_t	cast_specifics_us(va_list ap, t_ftprintf *f)
{
	uintmax_t ap_arg;

	if (f->ch.m_l)
		ap_arg = va_arg(ap, unsigned long int);
	else if (f->ch.m_ll)
		ap_arg = va_arg(ap, unsigned long long int);
	else if (f->ch.m_h)
		ap_arg = (unsigned short int)va_arg(ap, int);
	else if (f->ch.m_hh)
		ap_arg = (unsigned char)va_arg(ap, int);
	else if (f->ch.conv == 'p')
		ap_arg = (unsigned long int)va_arg(ap, long int);
	else
		ap_arg = va_arg(ap, unsigned int);
	return (ap_arg);
}
