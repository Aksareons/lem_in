/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:47:02 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/11 15:46:02 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_pr(t_ftprintf *f)
{
	f->ch.precision && f->ch.precision > f->ch.width
		? f->ch.f_zero = 1 : 0;
	if (f->ch.f_zero == 1)
		f->ch.space_zero = '0';
	else
		f->ch.space_zero = ' ';
	if (f->ch.width && !f->ch.f_minus)
		while ((f->ch.width--) != 1)
			free_buff(f, f->ch.space_zero);
	free_buff(f, '%');
	if (f->ch.width && f->ch.f_minus)
		while ((f->ch.width--) != 1)
			free_buff(f, f->ch.space_zero);
	ft_bzero(&(f->ch), sizeof(t_check));
}
