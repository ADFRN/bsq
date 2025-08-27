# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 09:37:28 by cn-goie           #+#    #+#              #
#    Updated: 2025/08/27 14:56:14 by cn-goie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = main.c ft_parsing.c read_file.c solve.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

HEADER = bsq.h

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c bsq.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	