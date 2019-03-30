/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:28:44 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:28:07 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		process_c(t_ftprintf *f, va_list ap)
{
	char	c;

	if (f->ch.f_zero == 1)
		f->ch.space_zero = '0';
	else
		f->ch.space_zero = ' ';
	c = (char)va_arg(ap, int);
	if (f->ch.width && !f->ch.f_minus)
		while ((f->ch.width--) != 1)
			free_buff(f, f->ch.space_zero);
	free_buff(f, c);
	if (f->ch.width && f->ch.f_minus)
		while ((f->ch.width--) != 1)
			free_buff(f, f->ch.space_zero);
	ft_bzero(&(f->ch), sizeof(t_check));
}
