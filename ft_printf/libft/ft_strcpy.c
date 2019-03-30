/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:26:17 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/27 17:28:09 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*srt1;
	char	*srt2;
	int		i;

	srt1 = (char *)src;
	srt2 = (char *)dst;
	i = 0;
	srt2[i] = srt1[i];
	while (srt1[i] != '\0')
	{
		srt2[i] = srt1[i];
		i++;
	}
	srt2[i] = '\0';
	return (dst);
}
