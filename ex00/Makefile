CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = Zombie.cpp randomChump.cpp newZombie.cpp main.cpp
OBJ = ${SRC:.cpp=.o}

NAME = Zombie

all : $(NAME)

$(NAME) : $(OBJ)
	$(CMP) $(VERSION) $(FLAGS) $^ -o $@
%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

