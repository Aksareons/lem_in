/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:17:20 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/29 18:33:59 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revers(char *str)
{
	int		i;
	char	*src;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	src = (char *)malloc(sizeof(char) * (i + 1));
	while (str[j])
	{
		src[j] = str[i - 1];
		j++;
		i--;
	}
	src[j] = '\0';
	return (src);
}

char		*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*src;

	i = 0;
	src = ft_revers((char *)str);
	while (src[i])
	{
		if (src[i] == ch)
			return ((char *)&str[ft_strlen(str) - i - 1]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	return (0);
}
