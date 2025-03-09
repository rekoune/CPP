# include "ClapTrap.hpp"

int main (){
    ClapTrap a("a");
    ClapTrap b("b");

    a.setattackDamage(2);
    b.setattackDamage(3);
    a.attack("b");
    a.attack("b");
    a.takeDamage(2);
    b.attack("a");
    b.attack("a");
}