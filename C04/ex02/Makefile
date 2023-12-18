# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 18:34:17 by ialvarez          #+#    #+#              #
#    Updated: 2023/11/28 18:34:39 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animals
CXX = clang++
RM = rm -f
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRCS =	main.cpp Animals.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@clear
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean test
