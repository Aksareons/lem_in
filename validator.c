/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:44:28 by voksenui          #+#    #+#             */
/*   Updated: 2019/06/29 05:44:15 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void        s_wght(t_inf *info)
{
    t_room      **begin;
    uintmax_t   num;

    Malloc_ch(begin = (t_room **)malloc(sizeof(t_room *) * 2));
    begin[0] = info->start;
    begin[1] = NULL;
    num = setting(&begin, info->start->num_edge);
    while (1)
    {
        if (!(num = setting(&begin, num)))
        {
            free(begin);
            break ;
        }
    }

}

void        validation(t_inf *info)
{
    if (!info->start || !info->end || !info->start->num_edge || !info->end->num_edge)
        print_error("can't find start/end pos");
    info->end->vstd = 0;
    info->start->wght = 1;
    s_wght(info);
    if (info->end->wght == 0)
        print_error("no way from start to end");
}