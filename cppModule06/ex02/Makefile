NAME		= ex02

SRC			=	main.cpp	\
				Base.cpp

HDRS		=	Base.hpp

OBJ			= $(SRC:.cpp=.o)

CXX			= clang++

CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98

.PHONY		: all clean fclean re
all			: $(NAME)

$(NAME)		: $(OBJ) $(HDRS) Makefile
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@

.o			: .cpp

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all