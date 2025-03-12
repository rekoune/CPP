# include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "Default Constructor of ClapTrap Called " << std::endl;
    this->name = "NULL";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name){
    std::cout << "An overloaded Constructor  of ClapTrap Called " << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap& original){
    std::cout << "Copy Constructor of ClapTrap Called" << std::endl;
        *this = original;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor  of ClapTrap Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original){
     if (this != &original){
        this->name = original.getName();
        this->hitPoints = original.getHitPoint();
        this->energyPoints = original.getEnergyPoints();
        this->attackDamage = original.getattackDamage();
    }
    return (*this);
}



void ClapTrap::attack( const std::string& target ){
    if (hitPoints > 0 && energyPoints){
        std::cout << "ClapTrap " << this->name
                  << " attacks " << target
                  << " causing " <<  this->attackDamage
                  << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (!hitPoints)
        std::cout << "ClapTrap " << this->name 
                  << " Died!" << std::endl;
    else
        std::cout << "No Energy left!" << std::endl;

}

void    ClapTrap::takeDamage( unsigned int amount ){
    if (hitPoints > 0 && energyPoints){
        std::cout << "ClapTrap " << this->name 
                  << " takes  " << amount 
                  << " amount of damage!" << std::endl;
        this->hitPoints -= amount;
        this->energyPoints--;
    }
    else if (hitPoints <= 0)
        std::cout << "ClapTrap " << this->name 
                  << " Died!" << std::endl;
    else
        std::cout << "No Energy left!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (hitPoints > 0 && energyPoints){
        std::cout << "ClapTrap " << this->name 
                  << " repairing an amount of   " << amount 
                  << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
    else if (hitPoints <= 0)
        std::cout << "ClapTrap " << this->name 
                  << "Died!" << std::endl;
    else
        std::cout << "No Energy left!" << std::endl;
}


std::string ClapTrap::getName( void )  const{
    return (this->name);
}
int ClapTrap::getHitPoint( void )  const{
    return (this->hitPoints);
}
int ClapTrap::getEnergyPoints( void )  const{
    return (this->energyPoints);
}
int ClapTrap::getattackDamage( void )  const{
    return (this->attackDamage);
}

void    ClapTrap::setName( const std::string& name ){
    this->name = name;
}
void    ClapTrap::setHitPoint( const int& hitPoints ){
    if (hitPoints > 0)
        this->hitPoints = hitPoints;
    else
        this->hitPoints = 0;
}
void    ClapTrap::setEnergyPoints( const int& energyPoints ){
    if (energyPoints > 0)
        this->energyPoints = energyPoints;
    else
        this->energyPoints = 0;
}
void    ClapTrap::setattackDamage( const int& attackDamage ){
    if (attackDamage > 0)
        this->attackDamage = attackDamage;
    else
        this->attackDamage = 0;
}

