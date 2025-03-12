# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){
    std::cout << "Default Constructor of DiamondTrap Called" << std::endl;
    this->energyPoints = 50;
    this->name = "NULL";
}

DiamondTrap::DiamondTrap( const std::string& name) : 
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"), 
    FragTrap(name + "_clap_name")
    {
        std::cout <<  "An Overloaded Constructor of DiamondTrap Called" << std::endl;
        this->energyPoints = 50;
        this->name = name;
}

DiamondTrap::DiamondTrap ( const DiamondTrap& original) : ClapTrap(original), ScavTrap(original), FragTrap(original){
    std::cout << "Copy Constructor of DiamondTrap Called" << std::endl;
    this->name = original.name;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& original){
    if (this != &original){
        ScavTrap::operator=(original);
        FragTrap::operator=(original);
        this->name = original.name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Destructor  of DiamondTrap Called" << std::endl;
}


void DiamondTrap::attack( const std::string& target ){
   ScavTrap::attack(target); 
}

void DiamondTrap::whoAmI(){
    std::cout << "Diamond name = " << name
              << "\nClap name   =  " << ClapTrap::name
              << std::endl;
}