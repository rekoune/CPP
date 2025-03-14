# include "../include/Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Constructed" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}
Cat::Cat( const Cat& original ){
    std::cout << "Copy constructor of Cat Called" << std::endl;
    this->brain = NULL;
    this->type = original.type;
}

Cat& Cat::operator=( const Cat& original){
    std::cout << "asignment operator of Cat Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
        delete this->brain;
        this->brain = new Brain(*original.brain);
    }
    return (*this);
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "Cat Destructed" << std::endl;
}

void Cat::makeSound( void ) const {
    std::cout << "Sound = Meow! Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain( void ) const {
    return (this->brain);
}

void Cat::setBrain( Brain*& brain ){
    if ( this->brain != brain){
        delete this->brain;
        this->brain = new Brain(*brain);
    }
}