/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:43:42 by voksenui          #+#    #+#             */
/*   Updated: 2019/06/06 17:58:28 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_commit(char *str)
{
	if (!str || !str[1])
		return (0);
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

int		is_edge(char *str)
{
	if (!str)
		return (0);
	if (*str == '#' || *str == '-')
		return (0);
	while (*str && *str != '-')
		str++;
	if (!(*str))
		return (0);
	str++;
	while (*str && *str != '-')
		str++;
	if (!(*str))
		return (1);
	return (0);
}

int		is_rooms(char *str)
{
	if (!str)
		return (0);
	if (*str == '#' || *str == 'L')
		return (0);
	while (*str && *str != ' ')
		str++;
	if (!(*str))
		return (0);
	str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (!(*str) || *str != ' ')
		return (0);
	str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (!(*str))
		return (1);
	return (0);
}

int		is_command(char *str)
{
	if (ft_strncmp(str, "##", 2) == 0 && str[2] != '#')
		return (1);
	return (0);
}
