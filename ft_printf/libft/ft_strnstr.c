/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:49:41 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/29 13:06:09 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		len;
	size_t		j;

	i = 0;
	len = 0;
	j = 0;
	if (src[0] == '\0')
		return ((char *)dst);
	while (dst[i] && i < n)
	{
		len = i;
		while (dst[len] == src[j] && (i + j) < n)
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
