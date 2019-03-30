/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:46:31 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/30 15:42:58 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		initialization(t_inf *info)
{
	info->ant_n = 0;
	info->room_n = 0;
	info->start = NULL;
	info->end = NULL;
	info->rooms = NULL;
	info->ways = NULL;
}

int				main(int ac, char **av)
{
	t_inf		info;

	if (ac == 2)
		info.fd = open(av[1], O_RDONLY);
	else if (ac == 1)
		info.fd = 0;
	else
		{
			ft_printf("Usage:\n\r%s < <file_name>\n\t%s <file_name>\n", av[0],av[0]);
			return (0);
		}
	initialization(&info);
	readfile(&info);
	validation(&info);
	find_ways(&info);
	if (DEB)
	{
		print_rooms(&info);
		ft_putchar_fd('\n', 2);
		print_ways(info.ways);
		ft_putchar_fd('\n', 2);
	}
	print_result(&info);
	return (0);
}