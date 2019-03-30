/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:45:18 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/27 17:29:32 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!src && !n)
		return (NULL);
	i = ft_strlen(src);
	j = 0;
	while (j < n)
	{
		if (j >= i)
			dst[j] = '\0';
		else
			dst[j] = src[j];
		j++;
	}
	return (dst);
}
