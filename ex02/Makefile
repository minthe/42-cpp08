# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 18:19:56 by vfuhlenb          #+#    #+#              #
#    Updated: 2023/05/17 19:47:10 by vfuhlenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS =	source/main.cpp \

OBJS = ${SRCS:.cpp=.o}

RM = rm -f

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "executable created: \033[32;1m./$(NAME)\033[0m"

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@echo "\033[34mclean success\033[0m"

fclean:
	$(RM) $(OBJS) $(NAME)
	@echo "\033[34mfclean success\033[0m"

re: fclean all

.PHONY: all clean fclean re
