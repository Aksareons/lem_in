/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:51:56 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/07 21:47:48 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *dst, const char *src)
{
	size_t		i;
	size_t		len;
	size_t		j;

	i = 0;
	len = 0;
	j = 0;
	if (src[0] == '\0')
		return ((char *)dst);
	while (dst[i])
	{
		len = i;
		while (dst[len] == src[j] && src[j])
		{
			j++;
			len++;
			if (j == ft_strlen(src))
				return ((char *)&dst[len - j]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
