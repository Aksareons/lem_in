/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:54:27 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/30 14:54:56 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_ant_num(t_inf *info)
{
	int		ret;
	char	*line;

	ret = get_next_line(info->fd, &line);
	if (ret < 0)
		print_error("can't read file");
	ret = 0;
	while (line[ret])
		if (!ft_isdigit(line[ret++]))
			print_error("wrong ant format");
	info->ant_num = (uintmax_t)ft_atoi(line);
	if (!(info->ant_num))
		print_error("wrong ant num");
	ft_putendl(line);
	ft_strdel(&line);
}

int			parse_command(char **line, t_inf *info)
{
	ft_putendl(*line);
	if (ft_strcmp("##start", *line) == 0)
	{
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		if (info->start)
			return (1);
		if (!is_room(*line) || parse_room(*line, info))
			return (1);
		info->start = info->rooms;
	}
	else if (ft_strcmp("##end", *line) == 0)
	{
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		if (info->end)
			return (1);
		if (!is_room(*line) || parse_room(*line, info))
			return (1);
		info->end = info->rooms;
	}
	return (0);
}

static int	parse_line(char **line, t_inf *info, int *room_parsed)
{
	if (is_comment(*line))
		return (0);
	else if (is_command(*line))
		return (parse_command(line, info));
	else if (!(*room_parsed) && is_room(*line))
		return (parse_room(*line, info));
	else if (is_edge(*line))
	{
		*room_parsed = 1;
		return (parse_edge(*line, info));
	}
	else
		return (1);
}

void		read_file(t_inf *info)
{
	char		*line;
	int			ret;
	int			room_parsed;

	room_parsed = 0;
	get_ant_num(info);
	while ((ret = get_next_line(info->fd, &line)))
	{
		if (ret < 0)
			print_error("can't read file");
		if (parse_line(&line, info, &room_parsed))
			break ;
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_putchar('\n');
	close(info->fd);
}