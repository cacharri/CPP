NAME = MutantWorldWeLiveIn
CXX = clang++
RM = rm -f
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) MutantStack.tpp
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@clear
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
