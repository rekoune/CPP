# include "DiamondTrap.hpp"

int main (){
   DiamondTrap diamond("player");
   diamond.whoAmI();
   diamond.attack("palyer2");
   diamond.attack("palyer3");
   diamond.attack("palyer4");
   diamond.takeDamage(50);

}