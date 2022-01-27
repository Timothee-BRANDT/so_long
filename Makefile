# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 18:32:37 by tbrandt           #+#    #+#              #
#    Updated: 2022/01/27 18:32:38 by tbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = so_long
I_DIR = include
L_FT = libft

SRC = main.c				\
	  parsing1.c			\
	  parsing2.c			\
	  parsing3.c			\
	  mlx_print_map.c		\
	  key_press.c			\
	  player_mouvements.c	\
	  put_player.c			\
	  check_exit.c			\

OBJ = $(SRC:%.c=%.o)

all: so_long.h $(NAME)

$(NAME): $(L_FT)/libft.a $(OBJ)
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_FT) -lft

$(L_FT)/libft.a:	
	make -C $(L_FT)

%.o: %.c
	$(CC) -g -o $@ -c $< -I mlx

clean:
	make clean -C $(L_FT)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(L_FT)
	rm  -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
