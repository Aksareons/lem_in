/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:31:18 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/30 15:42:57 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_end				*get_minwht_edge(t_end *end_end)
{
	t_end	*edge;
	t_end	*best_edge;
	t_end	*new_edge;

	edge = end_end;
	best_edge = NULL;
	while (edge)
	{
		if (!edge->room->vis)
		{
			if (!best_edge || edge->room->wht < best_edge->room->wht)
				best_edge = edge;
			else if (edge->room->wht == best_edge->room->wht &&
					edge->room->num_edg == 2)
				best_edge = edge;
		}
		edge = edge->next;
	}
	if (!best_edge)
		return (NULL);
	MALL_CHECK(new_edge = (t_end *)malloc(sizeof(t_end)));
	new_edge->room = best_edge->room;
	new_edge->next = NULL;
	return (new_edge);
}

void				delete_way(t_ways *way)
{
	t_end	*end;
	t_end	*prev;

	way->len = 0;
	if (!way->end)
		return ;
	end = way->end->next;
	while (end)
	{
		prev = end;
		end = end->next;
		prev->room->vis = 0;
		free(prev);
	}
	way->end->next = NULL;
}

void				get_new_way(t_ways *way, t_inf *info)
{
	t_end	*last_e;
	t_end	*min_edge;

	last_e = get_last_edge(way->end);
	last_e->room->vis = 1;
	way->len = 0;
	while (1)
	{
		min_edge = get_minwht_edge(last_e->room->end);
		if (!min_edge)
		{
			delete_way(way);
			return ;
		}
		way->len++;
		if (min_edge->room == info->start)
		{
			last_e->next = NULL;
			free(min_edge);
			return ;
		}
		last_e->next = min_edge;
		last_e = min_edge;
		min_edge->room->vis = 1;
	}
}

void				find_ways(t_inf *info)
{
	intmax_t		num_way;
	t_ways			way_arr[info->end->num_edg];

	num_way = 0;
	info->end->vis = 1;
	info->start->vis = 0;
	while (num_way < info->end->num_edg)
	{
		MALL_CHECK(way_arr[num_way].end = (t_end *)malloc(sizeof(t_end)));
		way_arr[num_way].end->room = info->end;
		way_arr[num_way].end->next = get_minwht_edge(info->end->end);
		if (way_arr[num_way].end->next)
			get_new_way(&(way_arr[num_way]), info);
		num_way++;
	}
	num_way = -1;
	while (++num_way < info->end->num_edg)
		if (!way_arr[num_way].len)
			get_new_way(&(way_arr[num_way]), info);
	save_ways(&way_arr[0], info);
	while (--num_way >= 0)
		if (!way_arr[num_way].len)
		{
			free(way_arr[num_way].end);
		}
}