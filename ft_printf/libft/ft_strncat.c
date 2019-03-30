/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:46:56 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/27 18:06:55 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *des, const char *src, size_t n)
{
	int		i;
	size_t	j;

	i = ft_strlen(des);
	j = 0;
	while (j < n && src[j])
	{
		des[i] = src[j];
		i++;
		j++;
	}
	des[i] = '\0';
	return (des);
}
