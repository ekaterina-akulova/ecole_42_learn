SRCS		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -std=c++98 #-Wshadow -Wno-shadow
NAME		= Animal

.PHONY:		all clean fclean re
all:		$(NAME)
$(NAME):	$(OBJS) Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean $(NAME)