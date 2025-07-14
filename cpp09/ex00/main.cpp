# include "BitcoinExchange.hpp"

int main (int ac, char** av){
    if (ac < 2){
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    else if (ac > 2){
        std::cerr << "Error: Wrong number of argument." << std::endl;
        return (1);
    }
    BitcoinExchange btc (av[1]);
    if (!btc.loadInputData())
        std::cerr << "Error: could not open file." << std::endl;
    else
        btc.printResult();
}
