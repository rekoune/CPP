SRC= main.cpp BitcoinExchange.cpp BTCDataLoader.cpp
OBJ = $(SRC:.cpp=.o)
NAME = btc

CC = c++
FLAGS = -Wall -Wextra -Werror
STD = -std=c++98

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(STD) $(OBJ) -o $(NAME)
%.o:%.cpp BitcoinExchange.hpp BTCDataLoader.hpp
	$(CC) $(FLAGS) $(STD) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all