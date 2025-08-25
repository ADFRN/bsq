# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 10:11:20 by afournie          #+#    #+#              #
#    Updated: 2025/08/25 10:11:21 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 		main.c			\
					ft_check_map.c	\
					ft_split.c		\

OBJ			=		$(SRC:.c=.o)

CC			?=		cc

RM			?=		rm -f

CFLAGS		+=		-Wall -Wextra -Werror

CPPFLAGS	+=		-iquote "./"

NAME		=		bsq_exe

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
