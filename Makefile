CC	= gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = so_long
I_DIR = include
L_FT = libft

SRC = so_long.c		\

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(L_FT)/libft.a $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_FT) -lft

$(L_FT)/libft.a:
	make -C $(L_FT) 

%.o: %.c
	$(CC) -g -o $@ -c $< -I$(I_DIR)

clean:
	make clean -C $(L_FT)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(L_FT)
	rm  -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
