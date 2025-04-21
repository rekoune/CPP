CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

SRC = main.cpp  Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)

NAME = Bureaucrat

all : $(NAME)

$(NAME) : $(OBJ) Bureaucrat.hpp
	$(CMP) $(VERSION) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : all clean