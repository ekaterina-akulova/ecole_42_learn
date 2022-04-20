# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qabderus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 12:15:49 by qabderus          #+#    #+#              #
#    Updated: 2021/12/09 12:21:18 by qabderus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fractol.c fractol_utils.c mandelbrot.c strcmp.c atof.c fractol_utils_2.c

OBJS = $(SRCS:.c=.o)

HEADER = fractol.h

CC = gcc

DEP = $(OBJS:.o=.d)

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -MMD -Imlx -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) -g $(OBJS) -MMD -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(DEP)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
