/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:36:11 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/01 02:11:39 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word(char const *s, char c)
{
	size_t	i;
	int		word;
	int		newword;

	i = 0;
	word = 0;
	newword = 1;
	while (s[i])
	{
		if (newword && s[i] != c)
		{
			word++;
			newword = 0;
		}
		if (s[i] == c)
			newword = 1;
		i++;
	}
	return (word);
}

static char	*next(char const *s, char c, size_t *word)
{
	size_t	i;

	while (s[*word] == c)
		*word += 1;
	i = *word;
	while (s[*word])
	{
		if (s[*word] == c)
			break ;
		*word += 1;
	}
	return (ft_strsub(s, i, *word - i));
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**str;
	size_t	i;
	size_t	start;

	if (s)
	{
		len = word(s, c);
		if (!(str = (char**)malloc(sizeof(char*) * (len + 1))))
			return (NULL);
		i = 0;
		start = 0;
		while (len--)
		{
			str[i] = next(s, c, &start);
			i++;
		}
		str[i] = 0;
		return (str);
	}
	return (NULL);
}
