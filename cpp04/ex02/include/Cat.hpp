# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat  : public Animal{
    private:
        Brain *brain;
    public :
        Cat();
        Cat ( const Cat& original);
        ~Cat();
        Cat& operator=( const Cat& original);
        void    makeSound( void ) const;
        Brain*  getBrain( void ) const;
        void    setBrain ( Brain*& brain);

};

# endif