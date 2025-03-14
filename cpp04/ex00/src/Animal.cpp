# include "../include/Animal.hpp"

Animal::Animal(){
    std::cout << "Animal Constructed" << std::endl;
    this->type = "Animal";
}
Animal::Animal( const Animal& original ){
    std::cout << "Copy constructor of Animal Called" << std::endl;
    this->type = original.type;
}
Animal& Animal::operator=( const Animal& original){
    std::cout << "asignment operator of Animal Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
    }
    return (*this);
}
Animal::~Animal(){
    std::cout << "Animal Destructed" << std::endl;
}

void Animal::makeSound( void ) const {
    std::cout << "Sound = Animal Sound" << std::endl;
}

std::string Animal::getType ( void ) const{
    return (this->type);
}