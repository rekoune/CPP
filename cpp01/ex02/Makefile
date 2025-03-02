CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = main.c
OBJ = main.o

NAME = program

all : $(NAME)

$(NAME) : $(OBJ)
	$(CMP) $(VERSION) $(FLAGS) $^ -o $@
%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
	
re : all clean