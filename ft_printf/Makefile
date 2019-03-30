# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 21:30:50 by voksenui          #+#    #+#              #
#    Updated: 2019/02/20 07:24:06 by voksenui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIB			=	libft/
LIB_N		=	libft.a

SRC			=	process_diuoxp.c cast_specifics.c ft_printf.c \
			 parse.c process_c.c process_pr.c process_s.c \
			 process_f.c


OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
C			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	cp $(LIB)$(LIB_N) $(NAME)
	ar -r $(NAME) $(OBJ)

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

