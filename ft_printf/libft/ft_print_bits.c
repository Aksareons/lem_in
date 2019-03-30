/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:11:16 by voksenui          #+#    #+#             */
/*   Updated: 2019/01/13 18:37:18 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int		i;
	int		l;
	char	s[8];

	i = 256;
	l = 8;
	while (i >>= 1)
		s[--l] = (octet & i);
	write(1, s, 8);
}
