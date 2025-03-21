# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat  : public Animal{
    public :
        Cat();
        Cat ( const Cat& original);
        ~Cat();
        Cat& operator=( const Cat& original);
        void    makeSound( void ) const;

};

# endif