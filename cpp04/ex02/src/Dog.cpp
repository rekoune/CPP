# include "../include/Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Constructed" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}
Dog::Dog( const Dog& original ){
    std::cout << "Copy constructor of Dog Called" << std::endl;
    this->brain = NULL;
    *this = original;
}
Dog& Dog::operator=( const Dog& original){
    std::cout << "asignment operator of Dog Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
        delete this->brain;
        this->brain = new Brain(*original.brain);
    }
    return (*this);
}
Dog::~Dog(){
    delete this->brain;
    std::cout << "Dog Destructed" << std::endl;
}

void Dog::makeSound( void ) const{
    std::cout << "Sound = Woof! Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain( void ) const {
    return (this->brain);
}
void Dog::setBrain( Brain*& brain ){
    if ( this->brain != brain){
        delete this->brain;
        this->brain = new Brain(*brain);
    }
}