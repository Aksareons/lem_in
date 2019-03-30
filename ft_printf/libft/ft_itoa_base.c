/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 05:28:44 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:24:37 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(size_t value, int base)
{
	int					i;
	size_t				b;
	char				*str;

	if (base < 2 || base > 16)
		return (0);
	i = 1;
	b = value;
	while (b /= base)
		i++;
	b = value;
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i--] = '\0';
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		str[i--] = "0123456789ABCDEF"[value % base];
		value = value / base;
	}
	return (str);
}
