# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array{
    private :
    T*     array;
    size_t lenght;
    class IndexOutOfBounds;
    public:
    Array();
    Array(unsigned int n);
    Array(Array& original);
    Array& operator=(Array& original);
    size_t size( void ) const;
    T& operator[](size_t index);
};

template<typename T>
class Array<T>::IndexOutOfBounds : public std::exception{
    public:
        const char* what( void ) const throw();
};
# include "Array.tpp"

# endif