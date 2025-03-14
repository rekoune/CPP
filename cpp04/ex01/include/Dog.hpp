# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog  : public Animal{
    private:
        Brain *brain;
    public :
        Dog();
        Dog ( const Dog& original);
        ~Dog();
        Dog& operator=( const Dog& original);
        void    makeSound( void ) const;
        Brain*    getBrain( void ) const;
        void    setBrain ( Brain*& brain);
};

# endif