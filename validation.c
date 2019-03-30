/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:19:35 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/30 15:43:01 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		init_set_weight_list(t_room ***new_list, uintmax_t *num_next,
								intmax_t *i, uintmax_t *num)
{
	*num_next = 0;
	MALL_CHECK(*new_list = (t_room **)malloc(sizeof(t_room *) * (*num + 1)));
	*i = -1;
	*num = 0;
}

void		set_weight_list_save_new(t_room ***new_list, uintmax_t num,
									t_room ***old_list)
{
	(*new_list)[num] = NULL;
	free(*old_list);
	*old_list = *new_list;
}

uintmax_t	set_weight_list(t_room ***list, uintmax_t num)
{
	uintmax_t	num_next;
	intmax_t	i;
	t_room		**new_list;
	t_end		*edge;

	init_set_weight_list(&new_list, &num_next, &i, &num);
	while ((*list)[++i] && (edge = (*list)[i]->end))
		while (edge)
		{
			if (!edge->room->wht)
			{
				edge->room->wht = (*list)[i]->wht + 1;
				if (edge->room->num_edg > 1)
				{
					num_next += edge->room->num_edg - 1;
					new_list[num++] = edge->room;
				}
				else
					edge->room->vis = 1;
			}
			edge = edge->next;
		}
	set_weight_list_save_new(&new_list, num, list);
	return (num_next);
}

void		set_weight(t_inf *info)
{
	t_room		**start_list;
	uintmax_t	num_start_next;

	MALL_CHECK(start_list = (t_room **)malloc(sizeof(t_room *) * 2));
	start_list[0] = info->start;
	start_list[1] = NULL;
	num_start_next = set_weight_list(&start_list, info->start->num_edg);
	while (1)
	{
		if (!(num_start_next = set_weight_list(&start_list, num_start_next)))
		{
			free(start_list);
			break ;
		}
	}
}

void		valid_and_set_weight(t_inf *info)
{
	if (!info->start || !info->end || !info->start->end || !info->end->end)
		print_error("can't find start/end pos");
	info->end->vis = 0;
	info->start->wht = 1;
	set_weight(info);
	if (info->end->wht == 0)
		print_error("no way from start to end");
}
