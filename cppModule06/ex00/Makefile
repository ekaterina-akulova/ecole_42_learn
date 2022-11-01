SRCS		= main.cpp Convert.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
RM			= rm -f
СFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= Convert

.PHONY:		all clean fclean re
all:		$(NAME)
$(NAME):	$(OBJS) Convert.hpp
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean $(NAME)