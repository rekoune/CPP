CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = main.cpp  src/Animal.cpp src/Cat.cpp src/Dog.cpp src/WrongCat.cpp src/WrongAnimal.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = include/Animal.hpp include/Cat.hpp include/Dog.hpp include/WrongCat.hpp include/WrongAnimal.hpp

NAME = Animal

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CMP) $(VERSION) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp 
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : all clean