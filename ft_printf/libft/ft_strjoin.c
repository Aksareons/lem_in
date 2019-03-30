/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:06:27 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/07 19:59:26 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		len = ((char)ft_strlen(s1) + (char)ft_strlen(s2) + 1);
		s = (char *)malloc(sizeof(char) * len);
		if (s)
		{
			while (*s1)
				s[i++] = *s1++;
			while (*s2)
				s[i++] = *s2++;
			s[i] = '\0';
			return (s);
		}
	}
	return (NULL);
}
