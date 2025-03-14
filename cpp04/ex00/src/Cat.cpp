# include "../include/Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Constructed" << std::endl;
    this->type = "Cat";
}
Cat::Cat( const Cat& original ){
    std::cout << "Copy constructor of Cat Called" << std::endl;
    this->type = original.type;
}
Cat& Cat::operator=( const Cat& original){
    std::cout << "asignment operator of Cat Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
    }
    return (*this);
}
Cat::~Cat(){
    std::cout << "Cat Destructed" << std::endl;
}

void Cat::makeSound( void ) const {
    std::cout << "Sound = Meow! Meow! Meow!" << std::endl;
}