#include "Zombie.hpp"

int main ()
{
    int N;

    N = 10;
    Zombie* zombieArray = zombieHorde(N, "test");
    for (int i = 0; i < N; i++)
        zombieArray[i].announce();
    delete [] zombieArray;
}