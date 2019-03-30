/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:33:36 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/07 19:43:18 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	if (!(s2 = (char *)malloc(sizeof(char) * (n) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i++] = '\0';
	return (s2);
}
