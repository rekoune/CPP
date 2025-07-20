# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <exception>
# include <cstdlib>
# include "Vector.hpp"
# include "Deque.hpp"

typedef std::string String;

class PmergeMe {
    private:
        PmergeMe();
        std::list<int> numbersList;
        Vector vector;
        Deque   deque;

    public :
        PmergeMe( const PmergeMe& original);
        PmergeMe(char** numbers);
        PmergeMe& operator=( const PmergeMe& original);
        class   InvalidNumberException;
        ~PmergeMe();
        void    parseNumbers(char** numbers);
        void    sort();
};

class PmergeMe::InvalidNumberException : public std::exception{
    public:
        const char* what( void ) const throw();
};



# endif