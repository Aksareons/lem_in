/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:07:13 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/28 16:56:27 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *des, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (des[i] && i < n)
		i++;
	j = i;
	while (src[i - j] && i + 1 < n)
	{
		des[i] = src[i - j];
		i++;
	}
	if (j < n)
		des[i] = '\0';
	return (j + ft_strlen(src));
}
