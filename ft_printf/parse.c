/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:04:43 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 15:59:35 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_parse_h(const char *format, t_ftprintf *f, int i)
{
	if (format[i] == 'h' && format[i + 1] != 'h')
	{
		f->ch.m_h = 1;
		i++;
		return (i);
	}
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		f->ch.m_hh = 1;
		i += 2;
		return (i);
	}
	return (i);
}

int		check_parse_l(const char *format, t_ftprintf *f, int i)
{
	if (format[i] == 'l' && format[i + 1] != 'l')
	{
		f->ch.m_l = 1;
		i++;
		return (i);
	}
	if (format[i] == 'l' && format[i + 1] == 'l')
	{
		f->ch.m_ll = 1;
		i += 2;
		return (i);
	}
	if (format[i] == 'L')
	{
		f->ch.m_d = 1;
		i++;
	}
	return (i);
}

int		check_parse_wp(const char *format, t_ftprintf *f, int i)
{
	if (ft_isdigit(format[i]))
	{
		f->ch.width = ft_atoi(&format[i]);
		while (format[i] && (ft_isdigit(format[i])))
			i++;
	}
	if (format[i] == 46)
	{
		f->ch.true_p = 1;
		i++;
		f->ch.precision = ft_atoi(&format[i]);
		while (format[i] && (ft_isdigit(format[i]) == 1))
			i++;
		(f->ch.precision) ? f->ch.f_zero = 0 : 0;
	}
	!f->ch.width ? f->ch.f_zero = 0 : 0;
	f->ch.width ? f->ch.t_width = 1 : 0;
	f->ch.width == f->ch.precision ? f->ch.width = 0 : 0;
	f->ch.pre_s = f->ch.precision;
	return (i);
}

int		check_parse_f(const char *format, t_ftprintf *f, int i)
{
	while (format[++i] == ' ' || format[i] == '#' || format[i] == '-'
		|| format[i] == '+' || format[i] == '0')
	{
		format[i] == ' ' ? f->ch.f_space = 1 : 0;
		format[i] == '#' ? f->ch.f_hash = 1 : 0;
		format[i] == '-' ? f->ch.f_minus = 1 : 0;
		format[i] == '+' ? f->ch.f_plus = 1 : 0;
		format[i] == '0' ? f->ch.f_zero = 1 : 0;
	}
	f->ch.f_minus == 1 ? f->ch.f_zero = 0 : 0;
	f->ch.f_plus == 1 ? f->ch.f_space = 0 : 0;
	return (i);
}
