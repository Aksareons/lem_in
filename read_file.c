/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:35:57 by voksenui          #+#    #+#             */
/*   Updated: 2019/06/06 18:15:15 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_ant(t_inf *info)
{
	int		tmp;
	char	*temp;

	tmp = get_next_line(info->fd, &temp);
	if (tmp < 0)
		print_error("can't read file");
	tmp = 0;
	while (temp[tmp])
		if (!ft_isdigit(temp[tmp++]))
			print_error("wrong ant format");
	info->ant_n = (uintmax_t)ft_atoi(temp);
	if (!(info->ant_n))
		print_error("wrong ant num");
	ft_putendl(temp);
	ft_strdel(&temp);	
}

int		read_command(t_inf *info, char **temp)
{
	ft_putendl(*temp);
	if (ft_strcmp("##start", *temp) == 0)
	{
		ft_strdel(temp);
		if (get_next_line(info->fd, temp) <= 0)
			print_error("can't read file");
		if (info->start)
			return (1);
		if (!is_rooms(*temp) || parse_room (*temp, info))
			return (1);
		info->start = info->rooms;
	}
	else if (ft_strcmp("##end", *temp) == 0)
	{
		ft_strdel(temp);
		if (get_next_line(info->fd, temp) <= 0)
			print_error("can't read file");
		if (info->end)
			return (1);
		if (!is_rooms(*temp) || parse_room (*temp, info))
			return (1);
		info->end = info->rooms;
	}
	return (0);
}

int		read_line(int *room_pars ,char **temp, t_inf *info)
{
	if (is_commit(*temp))
		return (0);
	else if (is_command(*temp))
		return (pars_command(temp, info));
	else if (!(*room_pars) && is_room(*temp))
		return (parse_room(*temp, info));
	else if (is_edge(*temp))
	{
		*room_pars = 1;
		return (pars_edge(*temp, info));
	}
	else
		return (1);
}

void	readfile(t_inf *info)
{
	char	*temp;
	int		tmp;
	int		pars_room;

	pars_room = 0;
	read_ant (temp);
	while ((tmp = get_next_line(info->fd, &temp)))
	{
		if (tmp < 0)
			print_error("can't read file");
		if (read_line(&pars_room, &temp, info))
			break ;
		ft_putendl(temp);
		ft_strdel(&temp);
	}
	ft_strdel(&temp);
	write(1, "\n", 1);
	close(info->fd);
}