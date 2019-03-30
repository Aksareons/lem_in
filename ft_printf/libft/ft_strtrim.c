/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:31:31 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/01 01:16:53 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i[2];
	char	*result;

	i[0] = 0;
	if (s)
	{
		if (!(result = ft_memalloc(ft_strlen(s) + 1)))
			return (NULL);
		ft_memcpy(result, s, ft_strlen(s));
		while (result[i[0]] && (result[i[0]] == ' ' ||
					result[i[0]] == '\n' || result[i[0]] == '\t'))
			i[0]++;
		i[1] = ft_strlen(s) - 1;
		while (result[i[1]] == ' ' || result[i[1]] == '\n'
				|| result[i[1]] == '\t')
			i[1]--;
		result[i[1] + 1] = '\0';
		return (ft_strdup(&result[i[0]]));
	}
	return (NULL);
}
