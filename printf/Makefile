FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEAD = ft_printf.h

SRC = ft_printf.c ft_read_format.c ft_printf_utils.c ft_buffer.c ft_numbers.c \
		type_s.c type_c.c type_di.c type_u.c type_x.c type_p.c ft_putchar_fd.c \
		ft_width.c anti_norminet.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean :clean
	@rm -f $(NAME)

re : fclean all

bonus:
	$(MAKE) all

.PHONY : 	all clean fclean re bonus
