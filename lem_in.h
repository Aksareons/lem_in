/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:46:28 by voksenui          #+#    #+#             */
/*   Updated: 2019/06/06 17:58:24 by voksenui         ###   ########.fr       */
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
	int				wght;		//vaga
	int				vstd;		//visit
	int				num_edge;	//ves grafa
	uintmax_t		ant;		//nomer ant chto zanyal room
	char			*name;		//name room :"room 1 i etc..."
	struct s_end	*end;		//end room
	struct s_room	*next;		//next element grafa(room)
}					t_room;

typedef struct		s_edge
{
	t_room			*room;
	struct s_end	*next;
	
}					t_edge;

typedef struct		s_ways
{
	t_edge			*end;			//end room
	intmax_t		len;			//leng link
	struct s_ways	*next;			
}					t_ways;

typedef struct		s_inf
{
	int				fd;				
	uintmax_t		ant_n;
	uintmax_t		room_n;
	t_room			*rooms;			//inf room
	t_ways			*ways;			//inf link
	t_room			*start;			//inf start
	t_room			*end;			//inf end
}					t_inf;

# endif
