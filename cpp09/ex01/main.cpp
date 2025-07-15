# include "RPN.hpp"

int main(int ac, char** av){
    if (ac != 2){
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return (1);
    }
    
    RPN rpn(av[1]);

    std::cout << rpn.getResult() << std::endl;
}