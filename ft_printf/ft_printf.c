/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:04:38 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:27:14 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_buff(t_ftprintf *f, char c)
{
	if (f->i + 1 == 4096)
	{
		write(1, f->buff, f->i);
		f->count += f->i;
		f->i = 0;
	}
	f->buff[f->i++] = c;
}

int		parse(const char *format, t_ftprintf *f, va_list *ap, int c)
{
	c = check_parse_f(format, f, c);
	c = check_parse_wp(format, f, c);
	c = check_parse_l(format, f, c);
	c = check_parse_h(format, f, c);
	return (print_value_type(format, f, ap, c));
}

int		print_value_type(const char *format, t_ftprintf *f, va_list *ap, int i)
{
	format[i] == 'c' ? process_c(f, *ap) : 0;
	format[i] == '%' ? process_pr(f) : 0;
	format[i] == 's' ? process_s(f, *ap) : 0;
	format[i] == 'f' ? process_f(*ap, f) : 0;
	format[i] == 'F' ? process_f(*ap, f) : 0;
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'x'
		|| format[i] == 'p' || format[i] == 'X' || format[i] == 'o'
		|| format[i] == 'u' || format[i] == 'b')
		check_base(format, f, i, ap);
	return (++i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_ftprintf	f;
	int			c;

	c = 0;
	va_start(ap, format);
	ft_bzero(&f, sizeof(t_ftprintf));
	while (format[c])
	{
		if (format[c] == '%')
		{
			if (format[c + 1] == '\0')
				break ;
			c = parse(format, &f, &ap, c);
			ft_bzero(&(f.ch), sizeof(t_check));
		}
		else
			free_buff(&f, format[c++]);
	}
	va_end(ap);
	if (f.i > 0)
		write(1, f.buff, f.i);
	f.count += f.i;
	return (f.count);
}
