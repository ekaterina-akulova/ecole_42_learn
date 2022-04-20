SRC = srcs/so_long_man.c srcs/map_man.c srcs/read_map_man.c srcs/free_man.c \
	srcs/moves_man.c srcs/so_long_norm.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

SRC_BONUS = srcs_bonus/so_long.c srcs_bonus/map.c srcs_bonus/read_map.c \
	srcs_bonus/free.c srcs_bonus/moves.c srcs_bonus/so_long_norm_bonus.c \
	srcs_bonus/so_long_norm2_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = my_libft/libft.a

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_BONUS:.c=.o}

GFLAGS = -Wall -Wextra -Werror

NAME = so_long

NAME_B = so_long_bonus

all: $(NAME)

bonus: $(NAME_B)

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd my_libft && make && cd ..
	$(CC) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B): $(OBJ_B)
	cd my_libft && make && cd ..
	$(CC) $(OBJ_B) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean :
	cd my_libft && make clean && cd ..
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

fclean : clean
	cd my_libft && make fclean && cd ..
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re :
	fclean all
	fclean bonus
	all

.PHONY: all clean fclean re
