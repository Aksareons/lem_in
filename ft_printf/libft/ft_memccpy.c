/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:06:05 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/07 22:35:10 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*q1;
	unsigned char	*q2;
	size_t			i;

	i = 0;
	q1 = (unsigned char *)dst;
	q2 = (unsigned char *)src;
	while (i < n)
	{
		q1[i] = q2[i];
		if (q2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
