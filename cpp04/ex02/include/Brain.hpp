# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{
    public :
        std::string ideas[100];
        Brain();
        Brain ( const Brain& original);
        ~Brain();
        Brain& operator=( const Brain& original);
};

# endif