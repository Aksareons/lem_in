/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:35:23 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/30 15:43:03 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways		*get_longest_way(t_ways *arr, intmax_t size)
{
	t_ways	*max_way;
	t_ways	*new_way;

	max_way = NULL;
	while (--size >= 0)
	{
		if (arr[size].len > 0)
			if (!max_way || max_way->len < arr[size].len)
				max_way = &arr[size];
	}
	if (!max_way)
		return (NULL);
	MALL_CHECK(new_way = (t_ways *)malloc(sizeof(t_ways)));
	new_way->len = max_way->len + 1;
	new_way->next = NULL;
	new_way->end = max_way->end;
	max_way->len = -1;
	max_way->end = NULL;
	return (new_way);
}

void		save_ways(t_ways *way_arr, t_inf *info)
{
	t_ways		*longest;
	t_end		*edge;

	info->ways = NULL;
	while (1)
	{
		longest = get_longest_way(way_arr, info->end->num_edg);
		if (!longest)
			return ;
		longest->next = info->ways;
		info->ways = longest;
		edge = info->ways->end;
		while (edge)
		{
			edge->room->ant = 0;
			edge = edge->next;
		}
	}
}