# include "Harl.hpp"


int main (int ac, char **av){
    if (ac != 2){
        std::cerr << "Invalid arguments!"<< std::endl;
        exit (1);
    }
    Harl test;
    test.complain(av[1]);
}