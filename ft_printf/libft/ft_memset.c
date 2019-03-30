/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:06:40 by voksenui          #+#    #+#             */
/*   Updated: 2018/10/26 11:36:17 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, unsigned int c, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = b;
	while (i < len)
		*(str + i++) = c;
	return (b);
}
