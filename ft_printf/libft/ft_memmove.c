/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:42:08 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/07 21:30:51 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*srt;
	char		*srt2;
	size_t		i;

	i = 0;
	srt = (char *)src;
	srt2 = (char *)dst;
	if (srt < srt2 && len != 0)
		while ((int)(--len) >= 0)
			*(srt2 + len) = *(srt + len);
	else
		while (i < len)
		{
			*(srt2 + i) = *(srt + i);
			i++;
		}
	return (dst);
}
