CMP = c++
FLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98

SRC = main.cpp Harl.cpp
OBJ = main.o Harl.o
NAME = harlFilter

all : $(NAME)

$(NAME) : $(OBJ)
	$(CMP)  $(VERSION) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean	
	rm -rf $(NAME)
re: fclean all
