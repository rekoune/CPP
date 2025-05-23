# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
    protected :
        std::string type;
    public :
        Animal();
        Animal ( const Animal& original);
        virtual ~Animal();
        Animal& operator=( const Animal& original);
        std::string getType( void ) const;
        virtual void    makeSound( void ) const = 0;

};

# endif