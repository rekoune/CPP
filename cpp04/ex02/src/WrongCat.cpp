# include "../include/WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "WrongCat Constructed" << std::endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat( const WrongCat& original ){
    std::cout << "Copy constructor of WrongCat Called" << std::endl;
    this->type = original.type;
}
WrongCat& WrongCat::operator=( const WrongCat& original){
    std::cout << "asignment operator of WrongCat Called" << std::endl;
    if ( this != &original){
        this->type = original.type;
    }
    return (*this);
}
WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructed" << std::endl;
}

void WrongCat::makeSound( void ) const {
    std::cout << "Sound = Meow! Meow! Meow!" << std::endl;
}