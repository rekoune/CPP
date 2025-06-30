# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <cstdlib>
# include <ctime>

template <typename T>
int easyfind (T container, int toFind);
template < typename T>
void randomValues(T& container, int size, int maxValue);
template < typename T>
void containerElements(T& container);
template <typename T>
void findValue(T container, int foFind);

class NotFoundException :public std::exception{
    public :
        const char* what () const throw(){
            return ("Exception: Value not found in container");
        }
};
# include "easyfind.tpp"

# endif