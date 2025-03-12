# include "ScavTrap.hpp"

int main (){
    ScavTrap scavTrap("playerA");
    
    scavTrap.attack("playerB");
    scavTrap.takeDamage(50);
    scavTrap.beRepaired(20);
    scavTrap.attack("playerB");
    scavTrap.guardGate();
}