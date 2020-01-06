# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 12:26:26 by hkchikec          #+#    #+#              #
#    Updated: 2020/01/04 01:54:27 by hkchikec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB=libft.a

LIB_DIR=libft/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

MINILIBX_DIRECTORY = ./minilibx_macos/

MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

NAME=fdf

UNITS= draw isometric read_map_tools read_map  main get_next_line bonus

SRC=$(addsuffix .c, $(UNITS))

OBJ=$(addsuffix .o, $(UNITS))

CC=gcc

CC_FLAGS=-Wall -Werror -Wextra -I.

all: lib $(NAME)

lib:
	make -C $(LIB_DIR) libft.a

$(NAME): lib
	$(CC) $(CC_FLAGS) -c $(SRC)
	$(CC) $(CC_FLAGS) $(OBJ) -L$(LIB_DIR) -lft -o $(NAME) -framework OpenGL -framework AppKit -lmlx

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

%.o : %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@