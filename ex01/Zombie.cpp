# include "Zombie.hpp"


Zombie::~Zombie( void ){
    std::cout << "The zombie " << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce( void ){
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string name ){
    this->name = name;
}