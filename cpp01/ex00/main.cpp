# include "Zombie.hpp"

int main (){
    Zombie* hona = newZombie("newZombie");
    hona->announce();
    randomChump("randomChump");
    delete hona;
}