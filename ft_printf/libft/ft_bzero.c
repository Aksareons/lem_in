/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:26:16 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/20 07:55:10 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*k;
	size_t			i;

	if (n <= 0)
		return ;
	k = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		k[i] = 0;
		i++;
	}
}