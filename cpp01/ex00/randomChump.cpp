# include "Zombie.hpp"

void randomChump( std::string name ){
    Zombie scopedZombie(name);
    scopedZombie.announce();
}