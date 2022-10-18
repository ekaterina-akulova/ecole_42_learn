CC      = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME     = HiThisIsBrain
SRCS     =	main.cpp
OBJS     = $(SRCS:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
run: all
	./HiThisIsBrain
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re:     fclean all
.PHONY: all clean fclean re