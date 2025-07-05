# ifndef MUSTANTSTACK_HPP
# define MUSTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{
    public :

        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack();
        ~MutantStack();
        MutantStack( const MutantStack<T>& original);
        MutantStack<T>& operator=( const MutantStack<T>& original);

        iterator begin ( void);
        iterator end ( void );

};



# include "MutantStack.tpp"

# endif