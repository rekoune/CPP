CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = main.cpp  ScalarConverter.cpp TypeDetector.cpp
OBJ = $(SRC:.cpp=.o)

NAME = convert

all : $(NAME)

$(NAME) : $(OBJ) ScalarConverter.hpp
	$(CMP) $(VERSION) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : all clean