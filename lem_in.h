/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:46:28 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/30 15:43:04 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define Malloc_ch(x) if (!(x)) exit (1)
# define DEB 0

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <inttypes.h>

typedef struct		s_room
{
	int				x;
	int				y;
	int				wht;
	int				vis;
	uintmax_t		ant;
	unsigned int	num_edg;
	char			*name;
	struct s_end	*end;
	struct s_room	*next;
}					t_room;

typedef struct		s_end
{
	t_room			*room;
	struct s_end	*next;
	
}					t_end;

typedef struct		s_ways
{
	t_end			*end;
	intmax_t		len;
	struct s_ways	*next;
}					t_ways;

typedef struct		s_inf
{
	int				fd;
	uintmax_t		ant_n;
	uintmax_t		room_n;
	t_room			*rooms;
	t_ways			*ways;
	t_room			*start;
	t_room			*end;
}					t_inf;

void				read_file(t_inf *info);
int					parse_command(char **line, t_inf *info);
void				get_ant_num(t_inf *info);
void				init_set_weight_list(t_room ***new_list, uintmax_t *num_next,
					intmax_t *i, uintmax_t *num);
void				set_weight_list_save_new(t_room ***new_list, uintmax_t num,
					t_room ***old_list);
uintmax_t			set_weight_list(t_room ***list, uintmax_t num);
void				save_ways(t_ways *way_arr, t_inf *info);
void				set_weight(t_inf *info);
void				valid_and_set_weight(t_inf *info);
t_end				*get_minwht_edge(t_end *end_end);
void				delete_way(t_ways *way);
void				get_new_way(t_ways *way, t_inf *info);
void				find_ways(t_inf *info);
t_ways				*get_longest_way(t_ways *arr, intmax_t size);
# endif