# include <iostream>
# include <vector>
# include "PmergeMe.hpp"


int main(int ac, char **av){
    if (ac <= 1){
        std::cerr << "Error: Invalid number of argument!"<< std::endl;
        return (1);
    }
    try{
        PmergeMe num(av);
        num.sort();
    }catch (std::exception& e){
        std::cerr << e.what() << std::endl;
        return (1);
    }
}