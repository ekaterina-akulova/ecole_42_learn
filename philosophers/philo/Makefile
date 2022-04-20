NAME 		= philo

PHILO 		= philo.h


SRC = main.c ft_atoi.c util_func.c init.c generate_philo_names.c

GCC 	= gcc
RM 		= rm -f
CFLAGS	= -Wall -Wextra -Werror 

.%c.o:
	$(GCC) $(CFLAGS) $< -o ${<:.c=.o}

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) -o $(NAME) $(OBJS)

clean:
	$(RM) *.o *.gch

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 