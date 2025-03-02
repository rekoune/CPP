CMP = c++
FLAGS = -Wall -Werror -Wextra
VERSION = -std=c++98

NAME = PhoneBook

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CMP) $(VERSION) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CMP) $(VERSION) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re:	fclean all