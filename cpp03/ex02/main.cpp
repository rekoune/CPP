# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main (){
    FragTrap FragTrap("playerC");

    FragTrap.attack("playerD");
    FragTrap.takeDamage(50);
    FragTrap.attack("playerD");
    FragTrap.attack("playerD");
    FragTrap.attack("playerD");
    FragTrap.highFivesGuys();

}