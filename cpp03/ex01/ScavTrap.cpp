# include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "Default Constructor of ScavTrap Called" << std::endl;
    this->name = "NULL";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap (const std::string& name){
    std::cout << "An overloaded Constructor  of ScavTrap Called " << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& original){
        *this = original;
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor  of ScavTrap Called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original){
     if (this != &original){
        this->name = original.getName();
        this->hitPoints = original.getHitPoint();
        this->energyPoints = original.getEnergyPoints();
        this->attackDamage = original.getattackDamage();
    }
    return (*this);
}

void ScavTrap::guardGate(){
   std::cout << "ScavTrap is now in Gate keeper mode." << std::endl; 
}

void ScavTrap::attack( const std::string& target ){
    if (hitPoints > 0 && energyPoints){
        std::cout << "ScavTrap " << this->name
                  << " attacks " << target
                  << " causing " <<  this->attackDamage
                  << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (!hitPoints)
        std::cout << "ScavTrap " << this->name 
                  << " Died!" << std::endl;
    else
        std::cout << "No Energy left!" << std::endl;

}