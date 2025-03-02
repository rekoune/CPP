# include <iostream>

void    printResult (int numArg, char **arg)
{
    for (int i = 1; i < numArg; i++){
        for (int j = 0; arg[i][j]; j++){
            arg[i][j] = std::toupper(arg[i][j]);
        }
        std::cout << arg[i];
    }
    std::cout << std::endl;
}

int main (int ac, char **av)
{
    switch (ac){
        case 1: 
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
            break;
        default: 
            printResult(ac, av);
            break;
    }
}