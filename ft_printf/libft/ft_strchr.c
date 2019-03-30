/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:48:52 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/07 19:17:37 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)str;
	while (src[i])
	{
		if (src[i] == ch)
			return (src + i);
		i++;
	}
	if (src[i] == ch)
		return (src + i);
	return (NULL);
}
