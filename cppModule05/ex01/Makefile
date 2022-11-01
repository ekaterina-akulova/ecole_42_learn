SRCS		= main.cpp Form.cpp Bureacrat.cpp Exeption.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= Form

.PHONY:		all clean fclean re
all:		$(NAME)
$(NAME):	$(OBJS) Bureacrat.hpp Form.hpp Exeption.hpp
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean $(NAME)