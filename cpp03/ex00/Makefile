CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

NAME = ClapTrap

all : $(NAME)

$(NAME) : $(OBJ)
	$(CMP) $(VERSION) $(FLAGS) $^ -o $(NAME)

%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : all clean