/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:46:00 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/29 17:48:34 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const char		*src;
	size_t			i;

	i = 0;
	src = arr;
	while (i < n)
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
