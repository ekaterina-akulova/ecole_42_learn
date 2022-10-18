

SRCS		= main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= ScavTrap

.PHONY:		all clean fclean re
all:		$(NAME)
$(NAME):	$(OBJS) ClapTrap.hpp ScavTrap.hpp
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean $(NAME)