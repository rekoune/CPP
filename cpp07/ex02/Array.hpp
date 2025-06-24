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
        Array(const Array& original);
        ~Array();
        Array& operator=(const Array& original);
        size_t size( void ) const;
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
};

template<typename T>
class Array<T>::IndexOutOfBounds : public std::exception{
    public:
        const char* what( void ) const throw();
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& Array);

# include "Array.tpp"

# endif