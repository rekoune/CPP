CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = main.cpp  Serializer.cpp
OBJ = $(SRC:.cpp=.o)

NAME = Serializer

all : $(NAME)

$(NAME) : $(OBJ) Serializer.hpp
	$(CMP) $(VERSION) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : all clean