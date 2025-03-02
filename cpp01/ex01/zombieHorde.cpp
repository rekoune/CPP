# include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ){
    if ( N <= 0 ){
        std::cerr << "Invalid number of Zombies" << std::endl;
        exit (1);
    }

    Zombie* zombieArray = new Zombie [N];

    for (int i = 0; i < N; i++)
        zombieArray[i].setName(name);
    return (zombieArray);
}