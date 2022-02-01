# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhanda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 14:20:42 by selhanda          #+#    #+#              #
#    Updated: 2021/12/21 14:20:45 by selhanda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=so_long
SRC=main.c get_next_line.c get_next_line_utils.c utils.c errors.c check_map.c move_f.c util.c ft_itoa.c
FLAGS=-Imlx -c $< -o $@
FFLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o
OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) 
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FFLAGS) $(NAME)

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean $(NAME)
