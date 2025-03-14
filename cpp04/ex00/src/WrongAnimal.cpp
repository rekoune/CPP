# include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal Constructed" << std::endl;
    this->type = "WrongAnimal";
}
WrongAnimal::WrongAnimal( const WrongAnimal& original ){
    std::cout << "Copy constructor of WrongAnimal Called" << std::endl;
    this->type = original.type;
}
WrongAnimal& WrongAnimal::operator=( const WrongAnimal& original){
    std::cout << "asignment operator of WrongAnimal Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
    }
    return (*this);
}
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructed" << std::endl;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "Sound = WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType ( void ) const{
    return (this->type);
}