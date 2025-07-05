SRC= main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = MutantStack

CC = c++
FLAGS = -Wall -Wextra -Werror
STD = -std=c++98

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(STD) $(OBJ) -o $(NAME)
%.o:%.cpp MutantStack.tpp MutantStack.hpp
	$(CC) $(FLAGS) $(STD) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all