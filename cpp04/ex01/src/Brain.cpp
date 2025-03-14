# include "../include/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Constructed" << std::endl;
}
Brain::Brain( const Brain& original ){
    std::cout << "Copy constructor of Brain Called" << std::endl;
    for ( int i = 0 ; i < 100; i++ )
        this->ideas[i] = original.ideas[i];
}
Brain& Brain::operator=( const Brain& original){
    std::cout << "asignment operator of Brain Called" << std::endl;
    if (this != &original)
        for ( int i = 0 ; i < 100; i++ )
            this->ideas[i] = original.ideas[i];
    return (*this);
}
Brain::~Brain(){
    std::cout << "Brain Destructed" << std::endl;
}
