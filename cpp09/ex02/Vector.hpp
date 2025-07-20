# ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <list>
# include <iostream>

class Vector{
    private:
        std::vector<int> container;
    public:
        Vector();
        ~Vector();
        Vector (std::list<int>& numbersList);
        Vector(const Vector& original);
        Vector& operator=(const Vector& original);
        void    initialize (std::list<int>& numbersList);
        void    sort();
        std::vector<int>    fordJohnsonSort(std::vector<int> numbers);
        std::vector<std::pair<int, int> > makeSortedPairs(std::vector<int> numbers, int& odd);
        void    separatePairs(std::vector<std::pair<int, int> >& pairs, std::vector<int>& winners, std::vector<int>& losers);     
        void    insertIntoWinners(std::vector<int>& winners, std::vector<int>& losers, int& odd);
        int     binarySearch(int& value, std::vector<int>& container);
        int     Jacobsthal(int N);
        std::vector<int>    getInsertionOrder(std::vector<int>& losers);
        void    cleanLosers(std::vector<int>& losers, std::vector<int>& indexes);
        
};

# endif