/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 01:36:03 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/17 16:27:48 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

intmax_t	ft_intlen(intmax_t c)
{
	intmax_t	count;

	count = 0;
	while (c /= 10)
		count++;
	return (++count);
}
