SRCS		= main.cpp Bureaucrat.cpp Form.cpp Intern.cpp\
			PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
RM			= rm -f
СFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= FormExecutor

.PHONY:		all clean fclean re
all:		$(NAME)
$(NAME):	$(OBJS) Bureaucrat.hpp Form.hpp Intern.hpp\
			PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)
			$(RM) *_shrubbery
fclean:		clean
			$(RM) $(NAME)
re:			fclean $(NAME)