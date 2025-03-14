# include "../include/Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Constructed" << std::endl;
    this->type = "Dog";
}
Dog::Dog( const Dog& original ){
    std::cout << "Copy constructor of Dog Called" << std::endl;
    this->type = original.type;
}
Dog& Dog::operator=( const Dog& original){
    std::cout << "asignment operator of Dog Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
    }
    return (*this);
}
Dog::~Dog(){
    std::cout << "Dog Destructed" << std::endl;
}

void Dog::makeSound( void ) const{
    std::cout << "Sound = Woof! Woof! Woof!" << std::endl;
}
