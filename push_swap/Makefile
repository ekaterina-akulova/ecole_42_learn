NAME = push_swap

BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I. -Imy_libft/ 

LIBFT = -L my_libft -lft

SRCS = push_swap.c ft_push.c ft_swap.c ft_sorting.c ft_utils.c \
		ft_rotate.c new_sort.c push_swap_atoi.c

SRCS_BONUS = checker.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		checker_utils.c commands.c commands_2.c \
		commands_3.c love_norminette.c \
		love_norminette_2.c commands_norma.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

all: $(NAME)

bonus: $(BONUS)


$(NAME): $(OBJS)
	@echo "\n"
	@make -C my_libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(BONUS): $(OBJS_BONUS)
	@echo "\n"
	@make -C my_libft/
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(LIBFT)

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C my_libft/
	@echo "\nDeleting binaries..."
	@rm -f $(OBJS)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C my_libft/
	@echo "\nDeleting objects..."
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "\nDeleting executable..."
	@rm -f $(NAME) $(BONUS)
	@echo "\033[0m"

re: fclean all