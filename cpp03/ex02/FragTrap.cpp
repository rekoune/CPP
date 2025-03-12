# include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "Default Constructor of FragTrap Called" << std::endl;
    this->name = "NULL"; 
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap (const std::string& name){
    std::cout << "An overloaded Constructor  of FragTrap Called " << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& original){
        *this = original;
}

FragTrap::~FragTrap(){
    std::cout << "Destructor  of FragTrap Called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& original){
     if (this != &original){
        this->name = original.getName();
        this->hitPoints = original.getHitPoint();
        this->energyPoints = original.getEnergyPoints();
        this->attackDamage = original.getattackDamage();
    }
    return (*this);
}

void FragTrap::highFivesGuys( void ){
    std::cout << "FragTrap " << this->name << ": Hey, give me a high five! ✋" << std::endl;
}

void FragTrap::attack( const std::string& target ){
    if (hitPoints > 0 && energyPoints){
        std::cout << "FragTrap " << this->name
                  << " attacks " << target
                  << " causing " <<  this->attackDamage
                  << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (!hitPoints)
        std::cout << "FragTrap " << this->name 
                  << " Died!" << std::endl;
    else
        std::cout << "No Energy left!" << std::endl;

}