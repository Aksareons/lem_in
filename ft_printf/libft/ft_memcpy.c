/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:14:15 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/26 16:52:14 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *q1;
	char *q2;

	q1 = (char *)dst;
	q2 = (char *)src;
	if (!n || q1 == q2)
		return (dst);
	*q1 = *q2;
	while (n--)
		*q1++ = *q2++;
	return (dst);
}
